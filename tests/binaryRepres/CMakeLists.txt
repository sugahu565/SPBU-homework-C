add_executable(tests_hw12_1 tests.c)


target_link_libraries(tests_hw12_1 binaryRepres)

target_include_directories(tests_hw12_1 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src/hw12
)

set_target_properties(tests_hw12_1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

add_test(NAME tests_hw12_1 COMMAND tests_hw12_1)
