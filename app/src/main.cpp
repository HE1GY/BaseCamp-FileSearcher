#include "FileSearcher.h"

#include <filesystem>
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: SEARCH_COMMAND FILENAME_WITH_EXTENSION_TO_SEARCH" << std::endl;
		return 1;
	}

	std::wstringstream wss;
	wss << argv[1];
	std::wstring fileName{wss.str()};

#if defined(_WIN32)
	std::wstring dir{std::filesystem::path("C:\\")};
#else
	std::wstring dir{std::filesystem::path("/")};
#endif

	constexpr std::size_t thread_count{8ULL};
	std::wstring path = FileSearcher::SearchFile(fileName, dir, thread_count);

	std::wcout << (path.empty() ? L"Not Founded!" : path) << std::endl;

	return 0;
}
