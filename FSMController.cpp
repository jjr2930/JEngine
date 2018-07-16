#include "FSMController.h"
#include "State.h"
#include "Log.h"

void JEngine::FSM::FSMController::SetInt(std::wstring & name, int value)
{
    m_MIntValue[name] = value;
    m_ptrCurrentState->SetInt(name, value);
}

void JEngine::FSM::FSMController::SetBool(std::wstring & name, bool value)
{
    m_MBoolValue[name] = value;
    m_ptrCurrentState->SetBool(name, value);
}

void JEngine::FSM::FSMController::SetFloat(std::wstring & name, float value)
{
    m_MFloatValue[name] = value;
    m_ptrCurrentState->SetFloat(name, value);
}

void JEngine::FSM::FSMController::SetTrigger(std::wstring & name)
{
    m_MTriggerValue[name] = true;
    m_ptrCurrentState->SetTrigger(name);
}

void JEngine::FSM::FSMController::UseTrigger(std::wstring name)
{
    m_MTriggerValue[name] = false;
}

int JEngine::FSM::FSMController::GetInt(std::wstring & name)
{
    auto founded_iter = m_MIntValue.find(name);
    if (founded_iter != m_MIntValue.end())
    {
        return founded_iter->second;
    }

    LOG(L"GetInt : %s is not founded\n", name);
    return 0;
}

bool JEngine::FSM::FSMController::GetBool(std::wstring & name)
{
    auto foundedIter = m_MBoolValue.find(name);
    if (foundedIter != m_MBoolValue.end())
    {
        return foundedIter->second;
    }

    LOG(L"GetInt : %s is not founded\n", name);
    return false;
}

float JEngine::FSM::FSMController::GetFloat(const std::wstring & name)
{
    auto foundedIter = m_MFloatValue.find(name);
    if (foundedIter != m_MFloatValue.end())
    {
        return foundedIter->second;
    }

    LOG(L"GetFloat : %s is not founded", name);
    return 0.0f;
}

bool JEngine::FSM::FSMController::GetTrigger(std::wstring & name)
{
    auto foundedIter = m_MTriggerValue.find(name);
    if (foundedIter != m_MTriggerValue.end())
    {
        return foundedIter->second;
    }

    LOG(L"GetFloat : %s is not founded", name);
    return 0.0f;
}

void JEngine::FSM::FSMController::SetCurrentState(State * current)
{
    m_ptrCurrentState = current;
}

void JEngine::FSM::FSMController::SetNextState(State * next)
{
    m_ptrNextState = next;
}

JEngine::FSM::State * JEngine::FSM::FSMController::GetCurrentState()
{
    return m_ptrCurrentState;
}

JEngine::FSM::State* JEngine::FSM::FSMController::GetNextState()
{
    return m_ptrNextState;
}

void JEngine::FSM::FSMController::Update()
{
    if (nullptr == m_ptrNextState)
    {
        m_ptrCurrentState->Exit();
        m_ptrCurrentState = m_ptrNextState;
        m_ptrNextState = nullptr;
        m_ptrCurrentState->Enter();        
    }

    m_ptrCurrentState->Update();
}
