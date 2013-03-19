#pragma once

#include "WaitFreeQueue.h"
#include <boost/shared_ptr.hpp>

namespace Serverlib
{
	class Job
	{
	public:
		int iType_;

	};

	typedef boost::shared_ptr<Job> JobPtr;
	class BaseUser
	{
	private:
		BaseUser() {}
		~BaseUser() {}

	public:

	private:
		//WaitFreeQueue<JobPtr> cJobQueue_;	// this is a Mulit Producer single consumer queue!
	};
};