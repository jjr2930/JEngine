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
            ~State();
            Transition* AddTransition(std::wstring name, State* endState);
            void RemoveTransition(const std::wstring& key);

        public:
            virtual void Enter() {}
            virtual void Update() {}
            virtual void Exit() {}
        };
    }
}