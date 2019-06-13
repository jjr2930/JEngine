#include "JGameObject.h"

using namespace JSample;

JSample::JGameObject::JGameObject(JTransform * parent)
{
	_transform = static_cast<JTransform*>(AddComponent<JTransform>());
	if (nullptr != parent)
		parent->AddChild(_transform);

	wcout << this->_name << L"is created" << endl;
}

JSample::JGameObject::JGameObject(const wstring & newName, JTransform* parent)
{
	_name = newName;

	_transform = static_cast<JTransform*>(AddComponent<JTransform>());
	if (nullptr != parent)
		parent->AddChild(_transform);

	wcout << this->_name << L"is created" << endl;

	OnInitialized();
}

void JSample::JGameObject::DestroyComponent(JComponent * component)
{
	for (uint32_t i = 0; i < _components.GetCount(); i++)
	{
		if (_components[i] == component)
		{
			_components.RemoveByIndex(i);
			delete component;
			break;
		}
	}
}

JSample::JTransform * JSample::JGameObject::GetTransform()
{
	return _transform;
}

JRenderer * JSample::JGameObject::GetRenderer()
{
	return _renderer;
}

void JSample::JGameObject::OnInitialized()
{
	for (uint32_t i = 0; i < _components.GetCount(); i++)
	{
		_components[i]->OnInitialized();
	}

	for (uint32_t i = 0; i < _transform->GetChildCount(); i++)
	{
		//this logic is slow?? maybe??
		_transform->_childs[i]->GetGameObject()->OnInitialized();
	}
}

void JSample::JGameObject::OnEnable()
{
	for (uint32_t i = 0; i < _components.GetCount(); i++)
	{
		_components[i]->OnEnable();
	}

	for (uint32_t i = 0; i < _transform->GetChildCount(); i++)
	{
		_transform->_childs[i]->GetGameObject()->OnEnable();
	}
}

void JSample::JGameObject::OnUpdate()
{
	for (uint32_t i = 0; i < _components.GetCount(); i++)
	{
		_components[i]->OnUpdate();
	}

	for (uint32_t i = 0; i < _transform->GetChildCount(); i++)
	{
		_transform->_childs[i]->GetGameObject()->OnUpdate();
	}
}

void JSample::JGameObject::OnDisable()
{
	for (uint32_t i = 0; i < _components.GetCount(); i++)
	{
		_components[i]->OnDisable();
	}

	for (uint32_t i = 0; i < _transform->GetChildCount(); i++)
	{
		_transform->_childs[i]->GetGameObject()->OnDisable();
	}
}

void JSample::JGameObject::OnDestroy()
{
	for (uint32_t i = 0; i < _components.GetCount(); i++)
	{
		_components[i]->OnDestroy();
	}

	for (uint32_t i = 0; i < _transform->GetChildCount(); i++)
	{
		_transform->_childs[i]->GetGameObject()->OnDestroy();
	}
}
