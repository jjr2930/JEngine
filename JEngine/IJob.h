#pragma once
namespace JSample
{
	class IJob {
	public :
		virtual void DoJob() = 0;
		bool IsCompleted = false;
	};
}

using ptrIJob = JSample::IJob*;