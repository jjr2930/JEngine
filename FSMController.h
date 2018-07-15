#pragma once
#include "Object.h"
#include <unordered_map>
namespace JEngine
{
    namespace FSM
    {
        class State;
        class FSMController : public Object
        {
        public:
            void BuildStateTree();
            void SetInt(std::wstring& name, int value);
            void SetBool(std::wstring& name, bool value);
            void SetFloat(std::wstring& name, float value);
            void SetTrigger(std::wstring& name);

            int GetInt(std::wstring& name);
            bool GetBool(std::wstring& name);
            float GetFloat(std::wstring& name);           

        private:
            State* root = nullptr;
            State* m_ptrCurrentState = nullptr;
            
            std::unordered_map<std::wstring, bool> m_MBoolValue;
            std::unordered_map<std::wstring, int> m_MIntValue;
            std::unordered_map<std::wstring, float>m_MFloatValue;
            std::unordered_map<std::wstring, bool> m_MTriggerValue;
        };
    }
}