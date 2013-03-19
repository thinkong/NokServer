#pragma once

#include <boost/lockfree/queue.hpp>

namespace NokUtils
{
// requirements for queue
// T must have a copy constructor
// T must have a trivial assignment operator
// T must have a trivial destructor

	template <class T>
	class ThreadSafeQueue : private boost::lockfree::queue<T>
	{
	public:
		ThreadSafeQueue()
		: boost::lockfree::queue<T>(1024)
		{

		}
		void Push(const T& c)
		{
			this->push(c);
		}
		T Pop()
		{
			T ret;
			if (this->pop(ret))
				return ret;
			return NULL;
		}
		bool IsEmpty()
		{
			return this->empty();
		}
	};
};