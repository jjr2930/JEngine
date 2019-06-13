#pragma once

#include "../JObject.h"


namespace JSample
{
	class JGameObject;
	class JTransform;
	class JComponent : public JObject
	{
	private:
		JGameObject* _gameObject = nullptr;
		JTransform* _transform = nullptr;
	public:
		virtual ~JComponent();
		JGameObject* GetGameObject();
		void SetGameObject(JGameObject* gameObject);
		JTransform* GetTransform();
		void SetTransform(JTransform* transform);

		virtual void OnInitialized() {};
		virtual void OnEnable() {};
		virtual void OnUpdate() {};
		virtual void OnDisable() {};
		virtual void OnDestroy() {};
	};
}