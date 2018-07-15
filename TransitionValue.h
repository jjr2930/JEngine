#pragma once
#include "Object.h"
#include "Log.h"
#include "ConditionValue.h"
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
            BigAndEqual,
            Bigger
        };
        using E_TVCT = E_TransitionValueCompareType;

        
       
        class TransitionValue : public Object
        {
        public:
            void SetType(const E_TVT& value)
            {
                m_eType = value;
            }

            E_TVT GetType()
            {
                return m_eType;
            }  

            void SetCompareType(const E_TVCT& value)
            {
                m_eCompareType = value;
            }

            E_TVCT GetCompareType()
            {
                return m_eCompareType;
            }

            virtual bool IsCompleted(int value) 
            {
                LOG(L"It is not int type\n");
            };
            virtual bool IsCompleted(float value)
            {
                LOG(L"It is not float type\n");
            }
            virtual bool IsCompleted(bool value)
            {
                LOG(L"It is not bool type\n");
            }

        protected:
            E_TVT   m_eType         = E_TVT::None;
            E_TVCT  m_eCompareType  = E_TVCT::None;
        };

        using TV = TransitionValue;
        
        class BoolTV : TransitionValue
        {
        public:
            //TODO: 어떻게 템플릿으로 만들 수 있을까
            bool IsCompleted(bool value) override
            {
                switch (m_eCompareType)
                {
                    case E_TVCT::BigAndEqual:   return this->value >= value;
                    case E_TVCT::Bigger:        return this->value > value;
                    case E_TVCT::Equal:         return this->value == value;
                    case E_TVCT::Smaller:       return this->value < value;
                    case E_TVCT::SmallAndEqual: return this->value <= value;
                    default:
                }

                return false;
            }

        private:
            bool value;
            
        };

        class IntTV : TV
        {
        public:
            bool IsCompleted(int value) override
            {
                switch (m_eCompareType)
                {
                    case E_TVCT::BigAndEqual:   return this->value >= value;
                    case E_TVCT::Bigger:        return this->value > value;
                    case E_TVCT::Equal:         return this->value == value;
                    case E_TVCT::Smaller:       return this->value < value;
                    case E_TVCT::SmallAndEqual: return this->value <= value;
                    default:
                }

                return false;
            }
            
        private:
            E_TVCT m_campareType;
            int value;
        };

        class FloatTV :TV
        {
        public:
            bool IsCompleted(float value) override
            {
                switch (m_eCompareType)
                {
                    case E_TVCT::BigAndEqual:   return this->value >= value;
                    case E_TVCT::Bigger:        return this->value > value;
                    case E_TVCT::Equal:         return this->value == value;
                    case E_TVCT::Smaller:       return this->value < value;
                    case E_TVCT::SmallAndEqual: return this->value <= value;
                    default:
                }

                return false;
            }

            float value;
        };

        class TriggerTV :TV
        {
        public:
            bool IsCompleted(bool value)
            {
                return true;
            }
        };
    }
}