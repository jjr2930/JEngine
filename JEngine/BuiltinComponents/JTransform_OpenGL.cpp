#if __OPEN_GL__
#include "JTransform_OpenGL.h"
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
	//position = position;
}

void JTransform::SetRotation(const JVector3& rotation)
{
	//rotation = rotation;
}

void JTransform::SetScale(const JVector3& scale)
{
	//scale = scale;
}

void JTransform::SetPositionAndRotation(const JVector3& position, const JVector3& rotation)
{	

}

void JTransform::SetPositionAndRotationAndScale(const JVector3& position, const JVector3& rotation, const JVector3& size)
{	
}

void JTransform::SetRotationAndScale(const JVector3& rotation, const JVector3& size) 
{
}

void JTransform::SetPositionAndScale(const JVector3& position, const JVector3& size)
{
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
	for (size_t i = 0; i < _childs.GetCount(); i++)
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

#endif // __OPEN_GL__
