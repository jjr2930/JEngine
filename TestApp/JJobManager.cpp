#include "JJobManager.h"
#include "OSDepenciesCode\OSDC_Header.h"
#include "JJobWorker.h"
#include <thread>

using namespace JSample;

JobManager* JobManager::_instance = nullptr;

JSample::JobManager::JobManager()
{
	uint32_t threadCount = JSample::OSDC::GetNumberOfThread();
	threadCount = (threadCount >= 10) ? threadCount - 2 : threadCount;

	for (uint32_t i = 0; i < threadCount; i++)
	{
		JJobWorker* newWorker = new	JJobWorker(i);
		this->_jobWorkers.Add(newWorker);
	}
}

JobManager * JSample::JobManager::GetInstance()
{
	if (nullptr == _instance)
	{
		_instance = new JobManager();
	}

	return _instance;
}

JJobWorker* JSample::JobManager::GetJobWorker(uint32_t index)
{
	if (index > _jobWorkers.GetCount())
		throw;

	return _jobWorkers[index];
}

uint32_t JSample::JobManager::GetJobWorkerCount()
{
	return _jobWorkers.GetCount();
}

void JSample::JobManager::Start()
{
	for (uint32_t i = 0; i < _jobWorkers.GetCount(); i++)
	{
		_jobWorkers[i]->StartJobWorker();
	}
}
