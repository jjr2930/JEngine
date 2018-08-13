#pragma once
#include "State.h"

namespace JEngine
{
    namespace FSM
    {        
        class StateMachine : public State
        {
        public:
            void Enter() override;
            void Update() override;
            void Exit() override;

        private:
            State*                      mPtrRootState       = nullptr;
            State*                      mPtrCurrentState    = nullptr;
            std::vector<Transition*>    mTransitions;
        };
    }
}