#pragma once
#include <thread>
#include <cstdio>
#include "OSDepenciesCode\OSDC_Header.h"
#include "DataStructure\JQueue.h"
#include "IJob.h"

using namespace JSample::DataStructure;

namespace JSample
{
	
	class JJobWorker
	{
	private:		
		DataStructure::JQueue<IJob*> _jobQueue;
		std::thread _runnerThread;
		uint32_t _id;

	private:
		void Run();

	public:
		JJobWorker(uint32_t id);
		~JJobWorker();

		void StartJobWorker();
		void EnqueueJob(IJob* job);
	};
}