#if __DIRECTX_12__
#pragma once
#include "../JObject.h"
#include "JComponent.h"
#include "../BuiltInDataType/JVector3.h"
#include "../DataStructure/JList.h"
using namespace JSample::JDataType;
using namespace JSample::DataStructure;

namespace JSample
{
	class JTransform : public JComponent
	{
	public:
		JTransform();
		JVector3 position;
		JVector3 rotation;
		JVector3 scale;

		DataStructure::JList<JTransform*> _childs;
		JTransform* parent = nullptr;

		void SetPosition(const JVector3& position);
		void SetRotation(const JVector3& rotation);
		void SetScale(const JVector3& scale);
		void SetPositionAndRotation(const JVector3& position, const JVector3& rotation);
		void SetPositionAndRotationAndScale(const JVector3& position, const JVector3& rotation, const JVector3& scale);
		void SetRotationAndScale(const JVector3& rotation, const JVector3& scale);
		void SetPositionAndScale(const JVector3& position, const JVector3& scale);
		JVector3 GetPosition();
		JVector3 GetRotation();
		JVector3 GetScale();
		void AddChild(JTransform* child);
		void RemoveChild(const JTransform* child);
		uint32_t GetChildCount();
	};
}
#endif // __DIRECTX_12__