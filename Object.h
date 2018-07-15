#pragma once
#include "JConst.h"
namespace JEngine
{
    class Object
    {
    public:
        Object()
        {
            m_cPtrName = L"NewObject";
            m_iObjectID = m_iID++;
        }
        Object(char* cptrName, UINT iSize)
        {
            m_cPtrName = L"NewObject";
        }

#pragma region Getter
        UINT GetObjectID() const
        {
            return m_iObjectID;
        }
        std::wstring GetName() const
        {
            return m_cPtrName;
        }
#pragma endregion

#pragma region Setter
        void SetObjectID(const int& iNewID)
        {
            m_iObjectID = iNewID;
        }
        void SetName(std::wstring cPtrNewName)
        {
            m_cPtrName = cPtrNewName;
        }
#pragma endregion


    protected:
        static UINT m_iID;
        UINT m_iObjectID;
        std::wstring m_cPtrName = nullptr;
    };
}