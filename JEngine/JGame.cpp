#include "JGame.h"
#include "Renderers\JNativeRendererHeader.h"
#include "JScene.h"
#include "IJob.h"
#include "JGameObject.h"

using namespace JSample;

JSample::JGame::JGame(const std::wstring & fileName)
{
	//open file..
	//parse json...
	//building scene, by MultiThread....
}

void JSample::JGame::OpenStartSceneFile()
{

}

void JSample::JGame::ParseSceneFile()
{
	//json parser....
}

void JSample::JGame::SetTargetSceneToCurrentScene()
{
	_nativeRenderer->SetTargetScene(_scene);
}

void JSample::JGame::Update()
{
	uint32_t count = _scene->GetGameObjectCount();
	auto goList = _scene->GetGameObjects();

	for (uint32_t i = 0; i < count; i++)
	{
		(*goList)[i]->OnUpdate();
	}
}

void JSample::JGame::Render()
{	
	_nativeRenderer->Draw();
}
