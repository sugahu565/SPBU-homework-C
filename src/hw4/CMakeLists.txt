add_executable(sorting main.c sort.s)

set_source_files_properties(sort.s PROPERTIES
    C_CLANG_TIDY ""
    CXX_CLANG_TIDY ""
)