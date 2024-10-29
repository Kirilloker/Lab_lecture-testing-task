cmake_minimum_required(VERSION 3.10)

project(stack)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g")

add_library(stack stack.c)

add_executable(main main.c)
target_link_libraries(main stack)

add_executable(stack_tests stack_tests.c stack.c)
target_link_libraries(stack_tests stack gcov)

add_executable(benchmark benchmark.c stack.c)
target_link_libraries(benchmark stack gcov)
