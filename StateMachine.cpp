#include "StateMachine.h"

void JEngine::FSM::StateMachine::Enter()
{
    State::Enter();
    mPtrCurrentState = mPtrRootState;
    mPtrRootState->Enter();
}

void JEngine::FSM::StateMachine::Update()
{
    mPtrCurrentState->Update();
}

void JEngine::FSM::StateMachine::Exit()
{
    mPtrCurrentState->Exit();
}