cmake_minimum_required(VERSION 3.25)
project(ILoveC C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)


add_compile_options(
    "$<$<COMPILE_LANGUAGE:C>:-Wall>"
    "$<$<COMPILE_LANGUAGE:C>:-Wextra>"
    "$<$<COMPILE_LANGUAGE:C>:-Wpedantic>"
)

set(CMAKE_ASM_FLAGS "")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(src)