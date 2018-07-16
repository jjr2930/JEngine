#pragma once
#include "State.h"

namespace JEngine
{
    namespace FSM
    {        
        class StateMachine : public State
        {
        private:
            State * startState;

        };
    }
}