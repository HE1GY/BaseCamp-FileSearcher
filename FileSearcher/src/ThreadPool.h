#pragma once

#include <array>
#include <condition_variable>
#include <functional>
#include <future>
#include <queue>
#include <thread>

namespace FileSearcher
{
	class ThreadPool
	{
	public:
		using Task = std::function<void()>;

		explicit ThreadPool(std::size_t thread_count);
		~ThreadPool();

		template<class T>
		auto Enqueue(T task) -> std::future<decltype(task())>
		{
			auto wrapper = std::make_shared<std::packaged_task<decltype(task())()>>(std::move(task));
			{
				std::unique_lock<std::mutex> lock{m_event_mutex};
				m_tasks.emplace([=] {
					(*wrapper)();
				});
			}
			m_event_var.notify_one();
			return wrapper->get_future();
		}

	private:
		std::vector<std::thread> m_threads;
		std::queue<Task> m_tasks;
		bool m_stopping{false};
		std::condition_variable m_event_var;
		std::mutex m_event_mutex;
	};
}// namespace FileSearcher
