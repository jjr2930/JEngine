#include "JJobWorker.h"
#include "IJob.h"
#include <mutex>
#include "GameConfiguration.h"


void JSample::JJobWorker::StartJobWorker()
{
	this->_runnerThread = std::thread(&JJobWorker::Run, this);
}

void JSample::JJobWorker::EnqueueJob(IJob* job)
{
	_jobQueue.Enqueue(job);
} 

JSample::JJobWorker::JJobWorker(uint32_t id)
{
	std::cout << "job worker created : " << id << endl;
}

JSample::JJobWorker::~JJobWorker()
{
	cout << "jobWorker id :" << _id << "destructed";
}

void JSample::JJobWorker::Run()
{
	while (true)
	{
		for ( ;_jobQueue.GetCount() > 0; )
		{ 
			int jobCount = _jobQueue.GetCount();
			JSample::IJob* job = _jobQueue.Dequeue();
			job->DoJob();
			delete job;
		}

		std::this_thread::sleep_for(std::chrono::nanoseconds(GameConfiguration::GetInstance()->JOP_SLEEP_TIME));
	}
}
