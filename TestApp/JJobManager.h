#pragma once
#include "DataStructure\JList.h"

namespace JSample
{
	//forward declarations
	class JJobWorker;

	class JobManager {
	private:
		static JobManager* _instance;
		DataStructure::JList<JJobWorker*> _jobWorkers;

	private:
		JobManager();

	public:
		static JobManager* GetInstance();
		JJobWorker* GetJobWorker(uint32_t index);
		uint32_t GetJobWorkerCount();
		void Start();
	};

	
}