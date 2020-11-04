cmake_minimum_required(VERSION 3.18.0)

project(leetcode)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# enables warnings (as per https://stackoverflow.com/a/14235055)
if (CMAKE_COMPILER_IS_GNUCC)
  set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif (CMAKE_COMPILER_IS_GNUCC)

add_subdirectory(third-party/backward-cpp)

add_subdirectory(src)
