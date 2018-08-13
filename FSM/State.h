#pragma once
#include "../Core/Object.h"
#include <unordered_map>
#include "../Core/Log.h"
namespace JEngine
{
    namespace FSM
    {        
        class Transition;
        class StateMachine;
        using TransitionMap = std::unordered_map<std::wstring, Transition*>;
        class State : public Object
        {
        private:
            StateMachine * m_PtrParent       = nullptr;
            TransitionMap  m_mapTransition;
        public : 
            State(std::wstring name, StateMachine* parent);
            ~State();
            Transition* CreateTransition(std::wstring name, State* endState);
            void        RemoveTransition(const std::wstring& key);

        public:
            virtual void Enter() {}
            virtual void Update();
            virtual void Exit() {}
        };
    }
}