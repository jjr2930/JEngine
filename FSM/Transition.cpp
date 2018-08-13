#include "Transition.h"
#include "FSMController.h"

void JEngine::FSM::Transition::RemoveTransitionValue(const std::wstring & key)
{
    auto foundedIter = m_MapTV.find(key);
    if (foundedIter != m_MapTV.end())   //founded
    {
        m_MapTV.erase(foundedIter);
        return;
    }

    LOG(L"RemoveTranbsitionValue %s is not exist", key.c_str());
}

void JEngine::FSM::Transition::Update()
{
    m_bCompleted = true;
    for (auto iter = m_MapTV.begin();
        iter != m_MapTV.end();
        iter++)
    {
        if (!iter->second->IsCompleted())
        {
            m_bCompleted = false;
        }
    }

    if (m_bCompleted)
    {
        for (auto iter = m_MapTV.begin();
            iter != m_MapTV.end();
            iter++)
        {
            if (E_TVT::Trigger == iter->second->GetType())
            {
                m_ptrController->UseTrigger(iter->second->GetLookUpName());
            }
        }
    }
}

bool JEngine::FSM::Transition::IsCompleted()
{
    return m_bCompleted;
}

JEngine::FSM::Transition::Transition(std::wstring name, State* ptrStartState, State* ptrEndState)
{
    m_ptrStart = ptrStartState;
    m_ptrEnd = ptrEndState;
    m_name = name;
}

JEngine::FSM::Transition::~Transition()
{
    m_ptrStart = nullptr;
    m_ptrEnd = nullptr;

    for (auto iter = m_MapTV.begin();
        iter != m_MapTV.end();
        iter++)
    {
        delete(iter->second);
    }

    m_MapTV.clear();
}
JEngine::FSM::State* JEngine::FSM::Transition::GetStartState()
{
    return m_ptrStart;
}

JEngine::FSM::State* JEngine::FSM::Transition::GetEndState()
{
    return m_ptrEnd;
}

void JEngine::FSM::Transition::SetStartState(State* ptrStartState)
{
    m_ptrEnd = ptrStartState;
}

void JEngine::FSM::Transition::SetEndState(State* ptrEndState)
{
    m_ptrEnd = ptrEndState;
}

void JEngine::FSM::Transition::AddTransitionBoolValue(std::wstring name, std::wstring lookUpName, const E_TVCT & compareType, bool lookUpValue)
{
    TransitionValue* newTV = new BoolTV(name, lookUpName, lookUpValue, compareType, m_ptrController, this);
    auto foundedIter = m_MapTV.find(name);
    if (foundedIter == m_MapTV.end())   //not founded
    {
        m_MapTV.insert({ name, newTV });
        return;
    }

    LOG(L"AddTransitionValue %s is already exist", name.c_str());
}

void JEngine::FSM::Transition::AddTransitionIntValue(std::wstring name, std::wstring lookUpName, const E_TVCT & compareType, int lookUpValue)
{
    TransitionValue* newTV = new IntTV(name, lookUpName, lookUpValue, compareType, m_ptrController, this);
    auto foundedIter = m_MapTV.find(name);
    if (foundedIter == m_MapTV.end())   //not founded
    {
        m_MapTV.insert({ name, newTV });
        return;
    }

    LOG(L"AddTransitionValue %s is already exist", name.c_str());
}


void JEngine::FSM::Transition::AddTransitionFloatValue(std::wstring name, std::wstring lookUpName, const E_TVCT & compareType, float lookUpValue)
{
    TransitionValue* newTV = new FloatTV(name, lookUpName, lookUpValue, compareType, m_ptrController, this);
    auto foundedIter = m_MapTV.find(name);
    if (foundedIter == m_MapTV.end())   //not founded
    {
        m_MapTV.insert({ name, newTV });
        return;
    }

    LOG(L"AddTransitionValue %s is already exist", name.c_str());
}
void JEngine::FSM::Transition::AddTransitionTriggerValue(std::wstring name, std::wstring lookUpName)
{
    TransitionValue* newTV = new TriggerTV(name, lookUpName, m_ptrController, this);
    auto foundedIter = m_MapTV.find(name);
    if (foundedIter == m_MapTV.end())   //not founded
    {
        m_MapTV.insert({ name, newTV });
        return;
    }

    LOG(L"AddTransitionValue %s is already exist", name.c_str());
}
