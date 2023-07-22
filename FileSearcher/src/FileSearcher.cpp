#include "FileSearcher.h"
#include "ThreadPool.h"
#include <filesystem>
#include <future>
#include <iostream>
#include <vector>

namespace FileSearcher
{
	static std::atomic<bool> s_stop_search{false};

	std::wstring SearchFile(const std::wstring& file_name, const std::wstring& root_directory, size_t thread_count) noexcept
	{
		ThreadPool pool{thread_count};

		std::vector<std::future<std::wstring>> results;
		try
		{
			for (const auto& entry : std::filesystem::directory_iterator(root_directory))
			{
				if (entry.is_regular_file() && entry.path().filename() == file_name)
				{
					s_stop_search = true;
					return entry.path().wstring();
				}

				if (entry.is_directory())
				{
					results.emplace_back(pool.Enqueue([file_name, entry] {
						return SearchFile(file_name, entry.path().wstring());
					}));
				}
			}
		}
		catch (const std::filesystem::filesystem_error& e)//Access is denied to directories
		{
		}

		while (!results.empty())
		{
			auto has_result = std::find_if(results.begin(), results.end(), [](auto& future) { return future.valid(); });
			if (has_result == results.end()) continue;

			std::wstring file_path{(*has_result).get()};
			if (!file_path.empty())
			{
				s_stop_search = true;
				return file_path;
			}
			results.erase(has_result);
		}
		return {};
	}

	std::wstring SearchFile(const std::wstring& file_name, const std::wstring& directory) noexcept
	{
		if (s_stop_search) return {};
		try
		{
			for (const auto& entry : std::filesystem::directory_iterator(directory))
			{
				if (entry.is_regular_file() && entry.path().filename() == file_name)
				{
					return entry.path().wstring();
				}
				if (entry.is_directory())
				{
					std::wstring file_path{SearchFile(file_name, entry.path().wstring())};
					if (!file_path.empty())
						return file_path;
				}
			}
		}
		catch (const std::filesystem::filesystem_error& e)//Access is denied to directories
		{
		}
		return {};
	}
}// namespace FileSearcher