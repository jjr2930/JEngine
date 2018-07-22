#include "Object.h"

UINT JEngine::Object::m_iID = 0;

JEngine::Object::Object()
{
    m_name = L"NewObject";
    m_iObjectID = m_iID++;
}

JEngine::Object::Object(std::wstring cptrName)
{
    m_name = cptrName;
}

UINT JEngine::Object::GetObjectID() const
{
    return m_iObjectID;
}

std::wstring JEngine::Object::GetName() const
{
    return m_name;
}

void JEngine::Object::SetObjectID(const int & iNewID)
{
    m_iObjectID = iNewID;
}

void JEngine::Object::SetName(std::wstring cPtrNewName)
{
    m_name = cPtrNewName;
}