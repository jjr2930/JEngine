#include "JScene.h"

using namespace JSample;

JSample::JScene::JScene()
{
	OnInitialized();
	OnEnable();
}

JSample::JScene::~JScene()
{
	for (uint32_t i = 0; i < _objects.GetCount(); i++)
	{
		delete _objects[i];
	}
}

void JSample::JScene::OnInitialized()
{
	for (uint32_t i = 0; i < _objects.GetCount(); i++)
	{
		_objects[i]->OnInitialized();
	}
}

void JSample::JScene::OnEnable()
{
	for (uint32_t i = 0; i < _objects.GetCount(); i++)
	{
		_objects[i]->OnEnable();
	}
}

void JSample::JScene::OnUpdate()
{
	for (uint32_t i = 0; i < _objects.GetCount(); i++)
	{
		_objects[i]->OnUpdate();
	}
}

void JSample::JScene::OnDisable()
{
	for (uint32_t i = 0; i < _objects.GetCount(); i++)
	{
		_objects[i]->OnDisable();
	}
}

void JSample::JScene::OnDestroy()
{
	for (uint32_t i = 0; i < _objects.GetCount(); i++)
	{
		_objects[i]->OnDestroy();
	}
}

void JSample::JScene::AddObject(JGameObject * newGameObject)
{
	_objects.Add(newGameObject);
	wcout << L"Object " << newGameObject->GetName() << " is added in " << _name << endl;
}

void JSample::JScene::RemoveGameObject(JGameObject * oldGameObject)
{
	for (uint32_t i = 0; i < _objects.GetCount(); i++)
	{
		if (_objects[i]->GetID() == oldGameObject->GetID())
		{
			delete _objects[i];
			_objects.RemoveByIndex(i);
			break;
		}
	}
}

uint32_t JSample::JScene::GetGameObjectCount()
{
	return _objects.GetCount();
}

JList<JGameObject*>* JSample::JScene::GetGameObjects()
{
	return &_objects;
}
