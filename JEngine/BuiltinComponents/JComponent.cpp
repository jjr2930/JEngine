#include "JComponent.h"
#include "../JGameObject.h"
using namespace JSample;

JComponent::~JComponent()
{
	OnDestroy();
}

JGameObject* JComponent::GetGameObject()
{
	return _gameObject;
}

void JComponent::SetGameObject(JGameObject* gameObject)
{
	_gameObject = gameObject;
}

JTransform* JComponent::GetTransform()
{
	return _transform;
}

void JComponent::SetTransform(JTransform* transform)
{
	_transform = transform;
}

