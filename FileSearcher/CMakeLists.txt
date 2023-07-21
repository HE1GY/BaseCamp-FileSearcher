add_library(FileSearcher src/ThreadPool.cpp src/ThreadPool.h src/FileSearcher.cpp include/FileSearcher.h include/FileSearcher.h)
target_include_directories(FileSearcher PUBLIC include)
