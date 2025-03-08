add_library(ast STATIC)

set_target_properties(ast PROPERTIES CXX_STANDARD 23 CXX_EXTENSIONS OFF)

add_subdirectory(decl)
add_subdirectory(expr)
add_subdirectory(stmt)

target_link_libraries(ast PRIVATE compile_options parser)
