#include "ThreadPool.h"
#include <iostream>

namespace FileSearcher
{
	ThreadPool::ThreadPool(std::size_t thread_count)
	{
		for (int i = 0; i < thread_count; ++i)
		{
			m_threads.emplace_back([=, this] {
				while (true)
				{
					Task task;
					{
						std::unique_lock<std::mutex> lock{m_event_mutex};
						m_event_var.wait(lock, [=, this] { return m_stopping || !m_tasks.empty(); });

						if (m_stopping && m_tasks.empty()) break;

						task = std::move(m_tasks.front());
						m_tasks.pop();
					}
					task();
				}
			});
		}
	}
	ThreadPool::~ThreadPool()
	{
		{
			std::unique_lock<std::mutex> lock{m_event_mutex};
			m_stopping = true;
		}
		m_event_var.notify_all();
		for (auto& thread : m_threads)
		{
			thread.join();
		}
	}
}// namespace FileSearcher
