add_executable(sorting main.c sort.s)

set_source_files_properties(sort.s PROPERTIES
    CLANG_TIDY_ENABLED NO  # или FALSE
)
