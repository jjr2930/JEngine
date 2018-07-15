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

float JEngine::FSM::FSMController::GetFloat(std::wstring & name)
{
    auto foundedIter = m_MFloatValue.find(name);
    if (foundedIter != m_MFloatValue.end())
    {
        return foundedIter->second;
    }

    LOG(L"GetFloat : %s is not founded", name);
    return 0.0f;
}
