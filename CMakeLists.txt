cmake_minimum_required(VERSION 3.22)
project(Test)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

# 编译待测源码
add_subdirectory(src)

# 编译测试用例
add_subdirectory(test)

add_subdirectory(doctest)
