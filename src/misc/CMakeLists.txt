add_library(misc STATIC symbol.cpp)

set_target_properties(misc PROPERTIES CXX_STANDARD 23 CXX_EXTENSIONS OFF)

target_include_directories(misc PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(misc PRIVATE compile_options)
