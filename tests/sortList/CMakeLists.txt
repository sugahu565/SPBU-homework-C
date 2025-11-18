add_executable(sortListTest test.c utils.c)


target_link_libraries(sortListTest sortList)

target_include_directories(sortListTest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_SIR}/src/hw6
)

set_target_properties(sortListTest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)


add_test(NAME sortListTest COMMAND sortListTest)