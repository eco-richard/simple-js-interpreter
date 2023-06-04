cmake_minimum_required(VERSION 3.14)
project(simple-js-interpreter)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
