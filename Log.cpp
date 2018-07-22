#include "Log.h"

DEFINE_SINGLETON(JEngine::Log);
void JEngine::Log::PrintLog(const wchar_t * _Format, ...)
{
    m_strResult.clear();
    va_list list;
    va_start(list, _Format);

    va_end(list);

    wprintf(_Format);
}
