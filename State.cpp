#include "State.h"

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

JEngine::FSM::Transition* JEngine::FSM::State::AddTransition(std::wstring name, State * endState)
{
    Transition* newTransition = new Transition(name, this, endState);
    auto foundedIter = m_mapTransition.find(name);
    if (foundedIter == m_mapTransition.end())
    {
        m_mapTransition.insert({ name, newTransition });
        return;
    }

    LOG(L"%s is already exist\n", newTransition->GetName().c_str());
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