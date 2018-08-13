#include "State.h"
#include "Transition.h"

JEngine::FSM::State::State(std::wstring name, StateMachine* parent)
    :Object(name), 
     m_PtrParent(parent)
{        
}

JEngine::FSM::State::~State()
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

JEngine::FSM::Transition* JEngine::FSM::State::CreateTransition(std::wstring name, State * endState)
{
    Transition* newTransition = new Transition(name, this, endState);
    auto foundedIter = m_mapTransition.find(name);
    if (foundedIter == m_mapTransition.end())
    {
        m_mapTransition.insert({ name, newTransition });
        return newTransition;
    }

    LOG(L"%s is already exist\n", newTransition->GetName().c_str());
    return nullptr;
}

void JEngine::FSM::State::RemoveTransition(const std::wstring & key)
{
    auto foundedIter = m_mapTransition.find(key);
    if (foundedIter != m_mapTransition.end())
    {
        m_mapTransition.erase(foundedIter);
        return;
    }

    LOG(L"%s Is not exist\n", key.c_str());
}

void JEngine::FSM::State::Update()
{
    for (auto iter = m_mapTransition.begin(); 
        iter != m_mapTransition.end();
        ++iter)
    {
        Transition* curTransition = iter->second;
        curTransition->Update();
        if (curTransition->IsCompleted())
        {
            
        }
    }
}
