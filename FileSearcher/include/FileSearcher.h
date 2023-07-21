#pragma once
#include <string>

namespace FileSearcher
{
	std::wstring SearchFile(const std::wstring& file_name, const std::wstring& root_directory, size_t thread_count) noexcept;

	std::wstring SearchFile(const std::wstring& file_name, const std::wstring& directory) noexcept;
}// namespace FileSearcher
