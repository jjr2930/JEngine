#include "AttackComponent.h"
#include "../OSDepenciesCode/OSDC_Header.h"
#include "../JGameObject.h"
#include <iostream>
#include "../JJobWorker.h"
#include "../JJobManager.h"

using namespace std;

void JSample::AttackComponent::OnInitialized()
{
	this->_attackDelay = 1.0f;
	this->_attackRange = 1;
	this->_beforeAttackTime = 0.0f;
	this->_dmg = 1;

	uint32_t workerCount = JobManager::GetInstance()->GetJobWorkerCount();
	uint32_t myId = m_id;
	uint32_t workerIndex = myId % workerCount;
	_worker = JobManager::GetInstance()->GetJobWorker(workerIndex);
}

void JSample::AttackComponent::OnUpdate()
{	
	PtrAttackJob newJob = new AttackJob(this);
	_worker->EnqueueJob(newJob);
}

JSample::AttackJob::AttackJob(JSample::AttackComponent* com)
{
	this->_com = com;
}

void JSample::AttackJob::DoJob()
{
	float currentTime = JSample::OSDC::GetTickTime();
	if (currentTime - _com->_beforeAttackTime>= _com->_attackDelay)
	{
		wcout << _com->GetGameObject()->GetName() << L"Attack!!!" << L"Range : " << _com->_attackRange << L"DMG : " << _com->_dmg << endl;
		_com->_beforeAttackTime= currentTime;
	}
}
