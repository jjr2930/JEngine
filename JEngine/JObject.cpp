#include "JObject.h"

JSample::JObject::JObject()
{
	objectCount = (objectCount + 1) % INT32_MAX;
	m_id = objectCount;
}

wstring JSample::JObject::GetName()
{
	return _name;
}

void JSample::JObject::SetName(wstring value)
{
	_name = value;
}

uint32_t JSample::JObject::GetID() const
{
	return m_id;
}
