cmake_minimum_required(VERSION 3.25)
project(iLoveC C)

add_compile_options(-Wall -Wextra -Wpedantic)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(src)