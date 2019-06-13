#if __DIRECTX_12__
#include "JTransform_DX12.h"

using namespace JSample;

JSample::JTransform::JTransform()
{
	position.m_x = 0.0f;
	position.m_y = 0.0f;
	position.m_z = 0.0f;

	rotation.m_x = 0.0f;
	rotation.m_y = 0.0f;
	rotation.m_z = 0.0f;

	scale.m_x = 0.0f;
	scale.m_y = 0.0f;
	scale.m_z = 0.0f;
}

void JTransform::SetPosition(const JVector3& position)
{
	this->position = position;
	//position = position;
}

void JTransform::SetRotation(const JVector3& rotation)
{
	this->rotation = rotation;
	//rotation = rotation;
}

void JTransform::SetScale(const JVector3& scale)
{
	this->scale = scale;
	//scale = scale;
}

void JTransform::SetPositionAndRotation(const JVector3& position, const JVector3& rotation)
{
	this->position = position;
	this->rotation = rotation;
}

void JTransform::SetPositionAndRotationAndScale(const JVector3& position, const JVector3& rotation, const JVector3& scale)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}

void JTransform::SetRotationAndScale(const JVector3& rotation, const JVector3& scale)
{
	this->rotation = rotation;
	this->scale = scale;
}

void JTransform::SetPositionAndScale(const JVector3& position, const JVector3& scale)
{
	this->position = position;
	this->scale = scale;
}

JVector3 JTransform::GetPosition()
{
	return position;
}

JVector3 JTransform::GetRotation()
{
	return rotation;
}

JVector3 JTransform::GetScale()
{
	return scale;
}

void JTransform::AddChild(JTransform* child)
{
	child->parent->RemoveChild(child);
	child->parent = this;
	_childs.Add(child);
}

void JTransform::RemoveChild(const JTransform* child)
{
	for (uint32_t i = 0; i < _childs.GetCount(); i++)
	{
		if (_childs[i]->GetID() == child->GetID())
		{
			_childs.RemoveByIndex(i);
			return;
		}
	}
}

uint32_t JTransform::GetChildCount()
{
	return _childs.GetCount();
}

#endif // DIRECTX_12
