#pragma once
#include "../Core/Object.h"
#include "TransitionValue.h"
#include <unordered_map>

namespace JEngine
{
    namespace FSM
    {
        class State;
        class TransitionValue;

        class Transition : public Object
        {
        public:
            Transition(){}
            Transition(std::wstring name, State* ptrStartState, State* ptrEndState);
            ~Transition();
            
            State* GetStartState();
            State* GetEndState();
            void SetStartState(State* ptrStartState);
            void SetEndState(State* ptrEndState);            
            void AddTransitionBoolValue(std::wstring name, std::wstring lookUpName, const E_TVCT& compareType, bool lookUpValue);            
            void AddTransitionIntValue(std::wstring name, std::wstring lookUpName, const E_TVCT& compareType, int lookUpValue);            
            void AddTransitionFloatValue(std::wstring name, std::wstring lookUpName, const E_TVCT& compareType, float lookUpValue);
            void AddTransitionTriggerValue(std::wstring name, std::wstring lookUpName);
            void RemoveTransitionValue(const std::wstring& key);
            void Update();

            bool IsCompleted();

        private:
            State*          m_ptrStart      = nullptr;
            State*          m_ptrEnd        = nullptr;
            bool            m_bCompleted    = false;
            FSMController*  m_ptrController = nullptr;  
            std::unordered_map<std::wstring, TransitionValue*> m_MapTV;
        };
    }
}