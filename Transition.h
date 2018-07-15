#pragma once
#include "Object.h"
#include "TransitionValue.h"
#include <unordered_map>

namespace JEngine
{
    namespace FSM
    {
        class State;

        class Transition : public Object
        {
        public:
            Transition(){}
            Transition(State* ptrStartState, State* ptrEndState)
            {
                m_ptrStart  = ptrStartState;
                m_ptrEnd    = ptrEndState;
            }

            State* GetStartState()
            {
                return m_ptrStart;
            }

            State* GetEndState()
            {
                return m_ptrEnd;
            }

            void SetStartState(State* ptrStartState)
            {
                m_ptrEnd = ptrStartState;
            }

            void SetEndState(State* ptrEndState)
            {
                m_ptrEnd = ptrEndState;
            }

            void AddTransitionValue(TransitionValue* newTranstition)
            {
                auto foundedIter = m_MapTV.find(newTranstition->GetName());
                if (foundedIter == m_MapTV.end())   //not founded
                {
                    m_MapTV.insert({ newTranstition->GetName(),newTranstition });
                    return;
                }

                LOG(L"AddTransitionValue %s is already exist", newTranstition->GetName().c_str());
            }

            void RemoveTransitionValue(const std::wstring& key)
            {
                auto foundedIter = m_MapTV.find(key);
                if (foundedIter != m_MapTV.end())   //founded
                {
                    m_MapTV.erase(foundedIter);
                    return;
                }

                LOG(L"RemoveTranbsitionValue %s is not exist", key.c_str());
            }

        private:
            State* m_ptrStart;
            State* m_ptrEnd;

            std::unordered_map<std::wstring, TransitionValue*> m_MapTV;
        };
    }
}