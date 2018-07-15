#pragma once
namespace JEngine
{
    template<class T>
    class Singleton
    {
    public :
        static T& Instance()
        {
            if (nullptr == m_ptrInstance)
            {
                m_ptrInstance = new T();
            }

            return *m_ptrInstance;
        }
    protected:
        Singleton(){}
        static T* m_ptrInstance = nullptr
    };
}