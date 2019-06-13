#pragma once
#include "../IJob.h"
#include "../BuiltinComponents/JComponent.h"

namespace JSample
{
	class JJobWorker;
	class AttackComponent : public JComponent
	{
	public:
		float		_attackDelay;
		uint16_t	_attackRange;
		int			_dmg;
		float		_beforeAttackTime;
		JJobWorker* _worker				= nullptr;
		
		virtual void OnInitialized();
		virtual void OnUpdate();
	};

	class AttackJob : public IJob
	{
	private:
		AttackComponent* _com;

	public:
		AttackJob(AttackComponent* com);
		virtual void DoJob();
	};

	using PtrAttackJob = AttackJob*;
}