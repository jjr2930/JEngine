#pragma once
#include "Core/Object.h"
#include <vector>
#include <unordered_map>
#include "BuiltinComponents/Component.h"
#include "BuiltinComponents/TransfromDX.h"
namespace JEngine
{
    class GameInstance : public Object
    {
    public:        
        template<class T : public Component>
        T* AddComponent<T>()
        {
            T* newCom = new T();
            m_pComponents.push_back(newCom);
            return newCom;
        }

        template<class T : public Component>
        T* GetComponent<T>()
        {
            for (int i = 0; i < m_pComponents.size(); ++i)
            {
                T* check = dynamic_cast<T>(m_pComponents[i]);
                if (nullptr != check)
                {
                    return check;
                }
            }

            return nullptr;
        }

        void Initialize()
        {
            for (int i = 0; i < m_pComponents.size(); ++i)
            {
                m_pComponents[i]->Initialize();
            }
        }
        void Sleep()
        {
            for (int i = 0; i < m_pComponents.size(); ++i)
            {
                m_pComponents[i]->Sleep();
            }
        }
        void WakeUp()
        {
            for (int i = 0; i < m_pComponents.size(); ++i)
            {
                m_pComponents[i]->WakeUp();
            }
        }
        void Update()
        {
            for (int i = 0; i < m_pComponents.size(); ++i)
            {
                m_pComponents[i]->Update();
            }
        }
        void Destroy()
        {
            for (int i = 0; i < m_pComponents.size(); ++i)
            {
                m_pComponents[i]->Destroy();
            }
        }

        void SetSleep(const bool& value)
        {
            if (value != m_isSleep)
            {
                m_isSleep = value;
                if (value)
                {
                    WakeUp();
                }
                else
                {
                    Sleep();
                }
            }
        }

    private:
        Transform m_transfrom;
        std::vector<Component*> m_pComponents;
        bool m_isSleep = true;
    };
}