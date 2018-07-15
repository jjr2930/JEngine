#pragma once
#include <iostream>
#include <string>
#include <stdarg.h>
#include <thread>
#include "Singleton.h"

#define LOG(_FORMAT_, ...) \
JEngine::Log::Instance().PrintLog(_FORMAT_, __VA_ARGS__)

namespace JEngine
{
    class Log : public Singleton<Log>
    {
    public:
        const wchar_t* FILE_NAME = L"Log.txt";
        void PrintLog(const wchar_t* _Format, ... )
        {   
            m_strResult.clear();
            va_list list;
            va_start(list, _Format);

            va_end(list);

            wprintf(_Format );
        }

    private:
        std::wstring m_strResult;
    };
}