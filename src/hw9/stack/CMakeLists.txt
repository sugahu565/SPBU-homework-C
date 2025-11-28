add_library(stack stack.c stack.h)

target_include_directories(stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})