add_library(sortList sortList.c)

target_include_directories(sortList PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(hw_6_main main.c)
target_link_libraries(hw_6_main sortList)

set_target_properties(hw_6_main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
