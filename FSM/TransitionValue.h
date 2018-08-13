#pragma once
#include "../Core/Object.h"
#include "../Core/Log.h"
#include "ConditionValue.h"
#include "FSMController.h"

namespace JEngine
{
    namespace FSM
    {
        enum class E_TransitionValueType
        {
            None,
            Bool,
            Int,
            Float,
            Trigger
        };
        using E_TVT = E_TransitionValueType;

        enum class E_TransitionValueCompareType
        {
            None,
            Smaller,
            SmallAndEqual,
            Equal,
            NotEqual,
            BigAndEqual,
            Bigger
        };
        using E_TVCT = E_TransitionValueCompareType;

        
        class FSMController;
        class Transition;
        class TransitionValue : public Object
        {
        public:
            void SetType(const E_TVT& value);
            E_TVT GetType();

            std::wstring GetLookUpName();

            virtual bool IsCompleted() = 0;
        protected:
            E_TVT           m_eType                 = E_TVT::None;
            FSMController*  m_ptrFsmController      = nullptr;
            Transition*     m_ptrParentTransition   = nullptr;
            std::wstring    m_lookUpName;
        };

        using TV = TransitionValue;
        
        class BoolTV : public TransitionValue
        {
        public:
            BoolTV(std::wstring name, std::wstring lookUpName, bool lookValue, E_TVCT compareType, FSMController* ptrCtrl, Transition* ptrTransition)
            {
                m_name                  = name;
                m_lookUpName            = lookUpName;
                m_eType                 = E_TVT::Bool;
                m_eCompareType          = compareType;
                m_ptrFsmController      = ptrCtrl;
                m_ptrParentTransition   = ptrTransition;
                m_value                 = lookValue;
            }
            //TODO: 어떻게 템플릿으로 만들 수 있을까
            bool IsCompleted() override
            {
                bool controllerValue = m_ptrFsmController->GetBool(m_lookUpName);
                switch (m_eCompareType)
                {
                    case E_TVCT::Equal:     return this->m_value == m_value;
                    case E_TVCT::NotEqual:  return this->m_value != controllerValue;
                    default: 
                        LOG(L"Not supported yet");
                        break;
                }

                return false;
            }

        private:
            E_TVCT  m_eCompareType = E_TVCT::None;
            bool    m_value;
            
        };

        class IntTV : public TV
        {
        public:
            IntTV(std::wstring name, std::wstring lookUpName, int lookValue, E_TVCT compareType, FSMController* ptrCtrl, Transition* ptrTransition)
            {
                m_name = name;
                m_lookUpName = lookUpName;
                m_eType = E_TVT::Bool;
                m_eCompareType = compareType;
                m_ptrFsmController = ptrCtrl;
                m_ptrParentTransition = ptrTransition;
                m_value = lookValue;
            }

            bool IsCompleted() override
            {
                int controllerValue = m_ptrFsmController->GetInt(m_lookUpName);
                switch (m_eCompareType)
                {
                    case E_TVCT::BigAndEqual:   return this->m_value >= controllerValue;
                    case E_TVCT::Bigger:        return this->m_value > controllerValue;
                    case E_TVCT::Equal:         return this->m_value == controllerValue;
                    case E_TVCT::Smaller:       return this->m_value < controllerValue;
                    case E_TVCT::SmallAndEqual: return this->m_value <= controllerValue;
                    default: 
                        break;
                }

                return false;
            }
            
        private:
            E_TVCT  m_eCompareType = E_TVCT::None;
            int m_value;
        };

        class FloatTV : public TV
        {
        public:
            FloatTV(std::wstring name, std::wstring lookUpName, float lookValue, E_TVCT compareType, FSMController* ptrCtrl, Transition* ptrTransition)
            {
                m_name                  = name;
                m_lookUpName            = lookUpName;
                m_eType                 = E_TVT::Bool;
                m_eCompareType          = compareType;
                m_ptrFsmController      = ptrCtrl;
                m_ptrParentTransition   = ptrTransition;
                m_value                 = lookValue;
            }

            bool IsCompleted() override
            {
                float controllerValue = m_ptrFsmController->GetFloat(m_lookUpName);
                switch (m_eCompareType)
                {
                    case E_TVCT::BigAndEqual:   return this->m_value >= controllerValue;
                    case E_TVCT::Bigger:        return this->m_value > controllerValue;
                    case E_TVCT::Equal:         return this->m_value == controllerValue;
                    case E_TVCT::NotEqual:      return this->m_value != controllerValue;
                    case E_TVCT::Smaller:       return this->m_value < controllerValue;
                    case E_TVCT::SmallAndEqual: return this->m_value <= controllerValue;
                    default:
                        break;
                }

                return false;
            }

        private:
            E_TVCT  m_eCompareType = E_TVCT::None;
            float   m_value;
        };

        class TriggerTV : public TV
        {
        public:
            TriggerTV(std::wstring name, std::wstring lookUpName, FSMController* ptrCtrl, Transition* ptrTransition)
            {
                m_name = name;
                m_lookUpName = lookUpName;
                m_eType = E_TVT::Bool;
                m_ptrFsmController = ptrCtrl;
                m_ptrParentTransition = ptrTransition;
            }

            bool IsCompleted() override
            {
                return m_ptrFsmController->GetTrigger(m_lookUpName);
            }
        };
    }
}