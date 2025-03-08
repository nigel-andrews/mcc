add_subdirectory(generator)

add_library(parser STATIC context.cpp factory.cpp)
set_target_properties(parser PROPERTIES CXX_STANDARD 23 CXX_EXTENSIONS OFF)

add_dependencies(parser generator)

# Parser doesn't need it but the LSP freaks out because of the reflex include in
# lex.yy.h
find_path(REFLEX_PATH reflex)
target_compile_options(parser PRIVATE "-I${REFLEX_PATH}")

target_include_directories(parser PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_include_directories(parser PUBLIC ${CMAKE_BINARY_DIR}/src)

target_link_libraries(parser PRIVATE compile_options reflex_shared_lib
                                     generator)
