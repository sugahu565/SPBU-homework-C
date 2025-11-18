cmake_minimum_required(VERSION 3.25)
project(suffer C)

add_compile_options(-Wall -Wextra -Wpedantic)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)