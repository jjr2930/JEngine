#pragma once
#define DEFINE_SINGLETON(TYPE_NAME)\
TYPE_NAME* JEngine::Singleton<TYPE_NAME>::m_ptrInstance = nullptr; 

namespace JEngine
{
    template<class T>
    class Singleton
    {
    public:
        static T& Instance()
        {
            if (nullptr == m_ptrInstance)
            {
                m_ptrInstance = new T();
            }

            return *m_ptrInstance;
        }
    protected:
        Singleton() {}
        static T* m_ptrInstance;
    };
}