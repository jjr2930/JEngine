#pragma once
#include "Object.h"
namespace JEngine
{
    namespace FSM
    {
        
        class ConditionValue : public Object
        {
        public :
            enum class E_TYPE
            {
                None,
                Bool,
                Int,
                Float,
                Trigger,
            };

            E_TYPE GetType() 
            {
                return m_type;
            }

        private:
            E_TYPE m_type = E_TYPE::None;            
        };

        class BoolValue : public ConditionValue
        {
        public:
            bool GetValue()
            {
                return value;
            }

            void SetValue(bool value)
            {
                this->value = value;
            }
        private:
            bool value = false;
        };

        class IntValue : public ConditionValue
        {
        public :
            int GetValue()
            {
                return value;
            }
            void SetValue(int value)
            {
                this->value = value;
            }
        private:
            int value;
        };

        class FloatValue : public ConditionValue
        {
        public :
            float GetValue()
            {
                return value;
            }
            void SetValue(float value)
            {
                this->value = value;
            }

        private:
            float value;
        };

        class TriggerValue : public ConditionValue
        {
        public:
            bool GetValue()
            {
                return value;
            }
            void SetValue(bool value)
            {
                this->value = value;
            }
            void SetToUsed()
            {
                this->value = false;
            }
        private:
            bool value;
        };
    }
}