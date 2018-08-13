#include "TransitionValue.h"
#include "Transition.h"
#include "FSMController.h"
#include "../Core/Log.h"


void JEngine::FSM::TransitionValue::SetType(const E_TVT & value)
{   
    m_eType = value;    
}

JEngine::FSM::E_TVT JEngine::FSM::TransitionValue::GetType()
{
    return m_eType;
}
std::wstring JEngine::FSM::TransitionValue::GetLookUpName()
{
    return m_lookUpName;
}

