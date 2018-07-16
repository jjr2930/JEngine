#include "Object.h"

JEngine::Object::Object()
{
    m_name = L"NewObject";
    m_iObjectID = m_iID++;
}

JEngine::Object::Object(char * cptrName, UINT iSize)
{
    m_name = L"NewObject";
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