#pragma once
#include "Object.h"
#include "Transition.h"
#include <unordered_map>
#include "Log.h"
namespace JEngine
{
    namespace FSM
    {
        class State : public Object
        {
        private:
            std::unordered_map<std::wstring, Transition*> m_mapTransition;
        public : 
            ~State()
            {
                for (auto iter = m_mapTransition.begin(); 
                    iter != m_mapTransition.end(); 
                    iter++)
                {
                    delete(iter->second);
                    iter->second = nullptr;
                }
                
                m_mapTransition.clear();
            }

            void AddTransition(Transition* newTransition)
            {
                auto foundedIter = m_mapTransition.find(newTransition->GetName());
                if (foundedIter == m_mapTransition.end())
                {
                    m_mapTransition.insert({ newTransition->GetName(), newTransition });
                    return;
                }

                LOG(L"%s is already exist\n", newTransition->GetName().c_str());
            }

            void RemoveTransition(const std::wstring& key)
            {
                auto foundedIter = m_mapTransition.find(key);
                if (foundedIter != m_mapTransition.end())
                {
                    m_mapTransition.erase(foundedIter);
                    return;
                }

                LOG(L"%s Is not exist\n", key.c_str());
            }

        public:
            virtual void Enter() {}
            virtual void Update() {}
            virtual void Exit() {}

            void SetInt(std::wstring& name, int value);
            void SetBool(std::wstring& name, bool value);
            void SetFloat(std::wstring& name, float value);
            void SetTrigger(std::wstring& name);
        };
    }
}