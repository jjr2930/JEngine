#pragma once
#include "JGameObject.h"
#include "DataStructure\JList.h"

using namespace JSample::DataStructure;

namespace JSample
{
	class JScene : public JObject
	{
	private:
		JSample::DataStructure::JList<JGameObject*> _objects;
	public:
		JScene();
		virtual ~JScene();
		void OnInitialized();
		void OnEnable();
		void OnUpdate();
		void OnDisable();
		void OnDestroy();
		void AddObject(JGameObject* newGameObject);
		void RemoveGameObject(JGameObject* oldGameObject);
		uint32_t GetGameObjectCount();
		JList<JGameObject*>* GetGameObjects();
	};

	using ptrJScene = JScene*;
}