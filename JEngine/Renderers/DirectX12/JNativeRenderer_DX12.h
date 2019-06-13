#if __DIRECTX_12__

#pragma once

#include "../../GameConfiguration.h"
#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <d3dcompiler.h>

namespace JSample
{
	class JScene;
	using ptrJScene = JScene*;
	class JNativeRenderer
	{
	private:
		IDXGIFactory4*				_dxgiFactory		= nullptr;		
		ID3D12Device1*				_device				= nullptr;
		IDXGISwapChain3*			_swapChain			= nullptr;
		IDXGIAdapter1*				_adapter			= nullptr;
		ID3D12CommandQueue*			_commandQueue		= nullptr;
		ID3D12GraphicsCommandList*	_commandList		= nullptr;
		ID3D12DescriptorHeap*		_rtvDescriptorHeap	= nullptr;

		ID3D12Resource*				_renderTargets[GameConfiguration::FRAME_BUFFER_COUNT];
		ID3D12CommandAllocator*		_commandAllocator[GameConfiguration::FRAME_BUFFER_COUNT];
		ID3D12Fence*				_fence[GameConfiguration::FRAME_BUFFER_COUNT];
		D3D12_COMMAND_QUEUE_DESC	_commandQueueDesc;
		
		HANDLE	_fenceEvent;
		UINT64	_fenceValue[GameConfiguration::FRAME_BUFFER_COUNT];
		HRESULT _hr;
		HWND	_targetHWND;

		int		_frameIndex;
		int		_rtvDescriptorSize;
		bool	_setupIsDone = false;
		bool	_running = false;

		ptrJScene	_targetScene = nullptr;

	private:
		bool InitD3D();
		void Update();
		void UpdatePipeline();
		void Render();
		void CleanUp();
		void WaitForPreviousFrame();
		bool CreateCommandQueue();
		bool CreateSwapChain();

	public:
		JNativeRenderer(HWND targetHWND);
		~JNativeRenderer();
		void Setup();
		void Draw();
		bool GetSetupIsDone();
		void SetTargetScene(ptrJScene targetScene);
	};
}
#endif