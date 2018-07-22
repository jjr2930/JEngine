#pragma once
#include "JConst.h"
#include <string>
namespace JEngine
{
    class Object
    {
    public:
        Object();
        Object(std::wstring cptrName);
        UINT GetObjectID() const;
        std::wstring GetName() const;
        void SetObjectID(const int& iNewID);
        void SetName(std::wstring cPtrNewName);

    protected:
        static UINT m_iID;
        UINT m_iObjectID;
        std::wstring m_name = nullptr;
    };
}