#pragma once
#include "../Core/Object.h"
namespace JEngine
{
    class Component : public Object
    {
    public:
        void Initialize()
        {
            OnInitilzie();
        }
        void Sleep()
        {
            OnSleep();
        }
        void WakeUp()
        {
            OnWakeUp();
        }
        void Update()
        {
            OnUpdate();
        }
        void Destroy()
        {
            OnDestory();
        }


    protected:
        virtual void OnInitilzie(){}
        virtual void OnSleep(){}
        virtual void OnWakeUp(){}
        virtual void OnUpdate() {}
        virtual void OnDestory(){}
    };
}