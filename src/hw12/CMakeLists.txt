add_library(binaryRepres binaryRepresOfNum.c)
add_executable(hw12_1 main.c)
target_include_directories(binaryRepres PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(hw12_1 binaryRepres)

set_target_properties(hw12_1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
