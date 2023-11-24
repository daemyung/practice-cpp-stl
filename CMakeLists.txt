cmake_minimum_required(VERSION 3.18)
project(practice-cpp-stl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(fmt GIT_REPOSITORY https://github.com/fmtlib/fmt.git GIT_TAG 10.1.1)
FetchContent_MakeAvailable(fmt)

add_executable(format src/format.cpp)
target_link_libraries(format fmt)

add_executable(compile-time-vector-and-string src/compile-time-vector-and-string.cpp)

add_executable(safe-compare src/safe-compare.cpp)
