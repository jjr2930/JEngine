#pragma once
#include "JObject.h"
#include "DataStructure\JList.h"
#include "BuiltinComponents\JTransformHeader.h"
#include "BuiltinComponents\JRendererHeader.h"

#include <typeinfo>

namespace JSample {
	class JComponent;
	class JGameObject : public JObject
	{
	private:
		DataStructure::JList<JComponent*> _components;
		JTransform* _transform = nullptr;
		JRenderer* _renderer = nullptr;

	public:
		JGameObject(JTransform* parent = nullptr);
		JGameObject(const wstring& newName, JTransform* parent = nullptr);

		template<typename T>
		T* AddComponent();

		void DestroyComponent(JComponent* component);

		template<typename T>
		JComponent* GetComponent();

		JTransform* GetTransform();
		JRenderer* GetRenderer();

		void OnInitialized();
		void OnEnable();
		void OnUpdate();
		void OnDisable();
		void OnDestroy();
	};
	template<typename T >
	inline T* JGameObject::AddComponent()
	{
		JComponent* newCom = new T();

		newCom->SetGameObject(this);

		_components.Add(newCom);
		
		newCom->OnInitialized();

		return static_cast<T*>(newCom);
	}

	template<>
	inline JRenderer* JGameObject::AddComponent<JRenderer>()
	{
		JRenderer* newRenderer = new JRenderer();

		newRenderer->SetGameObject(this);

		_components.Add(newRenderer);

		_renderer = newRenderer;

		newRenderer->OnInitialized();

		return newRenderer;
	}


	template<typename T>
	inline JComponent * JGameObject::GetComponent()
	{
		for (size_t i = 0; i < _components.GetCount(); i++)
		{
			if (typeid(T*) == typeid(_components[i]))
			{
				return _components[i];
				break;
			}
		}

		return nullptr;
	}
}