cmake_minimum_required(VERSION 3.10)
project(stack)

add_library(stack stack.c)

add_executable(main main.c)
add_executable(stack_tests stack_tests.c stack.c)

target_link_libraries(main stack)
