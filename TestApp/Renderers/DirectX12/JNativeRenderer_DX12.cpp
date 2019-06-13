#if __DIRECTX_12__
#include "JNativeRenderer_DX12.h"
#include "../../JLogger.h"
#include "d3dx12.h"
#include "../../JScene.h"

bool JSample::JNativeRenderer::InitD3D()
{
	_hr = CreateDXGIFactory1(IID_PPV_ARGS(&_dxgiFactory));
	if (FAILED(_hr))
	{
		JSample::JLogger::LogError(L"CreateDXGIFactory1 failed");
		return false;
	}

	_adapter = nullptr;
	int adapterIndex = 0;
	bool adapterFound = false;

	while ((_dxgiFactory->EnumAdapters1(adapterIndex, &_adapter) != DXGI_ERROR_NOT_FOUND))
	{
		DXGI_ADAPTER_DESC1 desc;
		_adapter->GetDesc1(&desc);

		if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
		{
			adapterIndex++;
			continue;
		}

		_hr = D3D12CreateDevice(_adapter, D3D_FEATURE_LEVEL_11_0, __uuidof(ID3D12Device), nullptr);
		if (SUCCEEDED(_hr))
		{
			adapterFound = true;
			break;
		}

		adapterIndex++;
	}

	if (!adapterFound)
	{
		return false;
	}
	
	return true;
}


void JSample::JNativeRenderer::UpdatePipeline()
{
	WaitForPreviousFrame();

	_hr = _commandAllocator[_frameIndex]->Reset();
	if (FAILED(_hr))
	{
		JLogger::LogError(L"resetting command allocator is failed");
		_running = false;
	}

	_hr = _commandList->Reset(_commandAllocator[_frameIndex], NULL);
	if (FAILED(_hr))
	{
		JLogger::LogError(L"resetting comandlist is failed");
		_running = false;
	}

	_commandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(_renderTargets[_frameIndex], D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET));

	CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(_rtvDescriptorHeap->GetCPUDescriptorHandleForHeapStart(), _frameIndex, _rtvDescriptorSize);
	_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);

	const float clearColor[] = { 1.0f, 1.0f, 1.0f,1.0f };
	_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);

	_commandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(_renderTargets[_frameIndex], D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT));

	_hr = _commandList->Close();
	if (FAILED(_hr))
	{
		JLogger::LogError(L"Closing commandlist is failed");
		_running = false;
	}
}

void JSample::JNativeRenderer::Render()
{
	UpdatePipeline();

	ID3D12CommandList* ppCommnadList[] = { _commandList };

	_hr = _commandQueue->Signal(_fence[_frameIndex], _fenceValue[_frameIndex]);
	if (FAILED(_hr))
	{
		JLogger::LogError(L"command queue's signaling is failed");
		_running = false;
	}

	_hr = _swapChain->Present(0,0);
	if (FAILED(_hr))
	{
		JLogger::LogError(L"current backbuffer present is failed");
		_running = false;
	}
}

void JSample::JNativeRenderer::CleanUp()
{
	for (int i = 0; i < GameConfiguration::FRAME_BUFFER_COUNT; ++i)
	{
		_frameIndex = i;
		WaitForPreviousFrame();
	}

	BOOL fs = false;
	if (_swapChain->GetFullscreenState(&fs, nullptr))
	{ _swapChain->SetFullscreenState(false, nullptr); }

	SAFE_RELEASE_DX(_device);
	SAFE_RELEASE_DX(_swapChain);
	SAFE_RELEASE_DX(_commandQueue);
	SAFE_RELEASE_DX(_rtvDescriptorHeap);
	SAFE_RELEASE_DX(_commandList);

	for (int i = 0; i < GameConfiguration::FRAME_BUFFER_COUNT; ++i)
	{
		SAFE_RELEASE_DX(_renderTargets[i]);
		SAFE_RELEASE_DX(_commandAllocator[i]);
		SAFE_RELEASE_DX(_fence[i]);
	}
}

void JSample::JNativeRenderer::WaitForPreviousFrame()
{
	if (_fence[_frameIndex]->GetCompletedValue() < _fenceValue[_frameIndex])
	{
		_hr = _fence[_frameIndex]->SetEventOnCompletion(_fenceValue[_frameIndex], _fenceEvent);
		if (FAILED(_hr))
		{
			JLogger::LogError(L"set fenceevent failed");
			_running = false;
		}

		WaitForSingleObject(_fenceEvent, INFINITE);
	}

	_fenceValue[_frameIndex]++;

	_frameIndex = _swapChain->GetCurrentBackBufferIndex();
}

bool JSample::JNativeRenderer::CreateCommandQueue()
{
	_commandQueueDesc = {};
	_commandQueueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
	_commandQueueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

	_hr = _device->CreateCommandQueue(&_commandQueueDesc, IID_PPV_ARGS(&_commandQueue));
	if (FAILED(_hr))
	{
		JLogger::LogError(L"ERROR : command queue creating is failed");
		return false;
	}

	return true;
}

bool JSample::JNativeRenderer::CreateSwapChain()
{
	DXGI_MODE_DESC backBufferDesc = {};
	backBufferDesc.Width = GameConfiguration::SCREEN_WIDTH;
	backBufferDesc.Height = GameConfiguration::SCREEN_HEIGHT;
	backBufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

	DXGI_SAMPLE_DESC sampleDesc = {};
	sampleDesc.Count = 1;

	DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
	swapChainDesc.BufferCount = GameConfiguration::FRAME_BUFFER_COUNT;
	swapChainDesc.BufferDesc = backBufferDesc;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.OutputWindow = _targetHWND;
	swapChainDesc.SampleDesc = sampleDesc;
	swapChainDesc.Windowed = GameConfiguration::IS_FULL_SCREEN;

	IDXGISwapChain* tempSwapChain;
	
	_dxgiFactory->CreateSwapChain(
		_commandQueue,
		&swapChainDesc,
		&tempSwapChain);

	_swapChain = static_cast<IDXGISwapChain3*>(tempSwapChain);
	_frameIndex = _swapChain->GetCurrentBackBufferIndex();

	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
	rtvHeapDesc.NumDescriptors = GameConfiguration::FRAME_BUFFER_COUNT;
	rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
	rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;


	_hr = _device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&_rtvDescriptorHeap));
	if (FAILED(_hr)) 
	{
		JLogger::LogError(L"creating descriptor heap is failed");
		return false;
	}


	_rtvDescriptorSize = _device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
	
	CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(_rtvDescriptorHeap->GetCPUDescriptorHandleForHeapStart());

	for (UINT i = 0; i < GameConfiguration::FRAME_BUFFER_COUNT; i++)
	{
		_hr = _swapChain->GetBuffer(i, IID_PPV_ARGS(&_renderTargets[i]));
		if (FAILED(_hr))
		{
			return false;
		}

		_device->CreateRenderTargetView(_renderTargets[i], nullptr, rtvHandle);

		rtvHandle.Offset(1, _rtvDescriptorSize);
	}

	for (int i = 0; i < GameConfiguration::FRAME_BUFFER_COUNT; i++)
	{
		_hr = _device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&_fence[i]));
		if (FAILED(_hr))
		{
			JLogger::LogError(L"Creating fence is failed");
			return false;
		}

		_fenceValue[i] = 0;
	}

	_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
	if (_fenceEvent = nullptr)
	{
		JLogger::LogError(L"Creating event is failed");
		return false;
	}

	return true;
}

bool JSample::JNativeRenderer::GetSetupIsDone()
{
	return _setupIsDone;
}

void JSample::JNativeRenderer::SetTargetScene(ptrJScene targetScene)
{
	_targetScene = targetScene;
}

JSample::JNativeRenderer::JNativeRenderer(HWND targetHWND)
{
	this->_targetHWND = targetHWND;
	this->Setup();
}

JSample::JNativeRenderer::~JNativeRenderer()
{
}

void JSample::JNativeRenderer::Setup()
{
	if (!InitD3D())
	{
		JLogger::LogError(L"Init3D failed");
		_setupIsDone = false;
		return;
	}

	_setupIsDone = true;
}

void JSample::JNativeRenderer::Draw()
{
	UpdatePipeline();

	uint32_t count = _targetScene->GetGameObjectCount();
	auto list = _targetScene->GetGameObjects();
	for (uint32_t i = 0; i < list->GetCount(); ++i)
	{
		
	}
}
#endif