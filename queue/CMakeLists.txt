
cmake_minimum_required(VERSION 3.15)

# project(DataStructure LANGUAGES CXX)
project(DataStructure LANGUAGES C)

# We need an executable target
set(SOURCE_FILES queue_ll.c queue_ll_test.c)
add_executable(queue ${SOURCE_FILES})
