#include "JLogger.h"

INIT_SINGLETON(JSample::JLogger);

JSample::JLogger::JLogger()
{
	//create thread for save log
}

void JSample::JLogger::Log(const wstring & log)
{
	GetInstance()->OnLog(log);
}

void JSample::JLogger::LogWarnning(const wstring & warnningLog)
{
	GetInstance()->OnLogWarnning(warnningLog);
}

void JSample::JLogger::LogError(const wstring & errorLog)
{
	LogError(errorLog);
}

void JSample::JLogger::OnLog(const wstring & log)
{
	JLogElement newElement;
	newElement.type = E_LogElementType::Log;
	newElement.log = log + L"\n";
	_logs.Add(newElement);
}

void JSample::JLogger::OnLogWarnning(const wstring & warnningLog)
{
	JLogElement newElement;
	newElement.type = E_LogElementType::Warnning;
	newElement.log = warnningLog + L"\n";
	_logs.Add(newElement);
}

void JSample::JLogger::OnLogError(const wstring & errorLog)
{
	JLogElement newElement;
	newElement.type = E_LogElementType::Error;
	newElement.log = errorLog + L"\n";
	_logs.Add(newElement);
}


void JSample::JLogger::SaveLog()
{
	//save
	//sleep 1 millisec
}
