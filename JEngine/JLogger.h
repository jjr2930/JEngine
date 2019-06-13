#pragma once

#if __WINDOWS_10__
#include <string>
#include "Utilities_Macro.h"
#include "DataStructure\JList.h"

namespace JSample
{
	enum class E_LogElementType
	{
		Log = 0,
		Warnning,
		Error,
		Count
	};
	struct JLogElement
	{
	public:
		E_LogElementType type;
		wstring log;
	};

	class JLogger
	{
		SINGLETON(JLogger);
		
	private:
		DataStructure::JList<JLogElement> _logs;
		size_t _beforeSavedIndex = 0;
	public:
		JLogger();

		static void Log(const wstring& log);
		static void LogWarnning(const wstring& warnningLog);
		static void LogError(const wstring& errorLog);

		void OnLog(const wstring& log);
		void OnLogWarnning(const wstring& warnningLog);
		void OnLogError(const wstring& errorLog);
		void SaveLog();
	};
}
#endif // __WINDOWS_10__
