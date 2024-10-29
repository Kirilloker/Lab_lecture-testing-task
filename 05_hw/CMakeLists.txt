cmake_minimum_required(VERSION 3.10)
project(stack)

add_library(stack stack.c)

add_executable(main main.c)
add_executable(stack_tests stack_tests.c stack.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address,undefined -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -g")

target_link_libraries(main stack)