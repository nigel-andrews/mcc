cmake_minimum_required(VERSION 3.27)

project(mcc)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(compile_options INTERFACE)

target_compile_options(
  compile_options
  INTERFACE "-Wall"
            "-Wextra"
            "-pedantic"
            "-std=c++23"
            $<$<CONFIG:Release>:-O3>
            $<$<CONFIG:Release>:-Werror>
            $<$<CONFIG:Debug>:-O0>
            $<$<CONFIG:Debug>:-fno-inline>
            $<$<CONFIG:Debug>:-g3>
            $<$<CONFIG:Debug>:-fsanitize=address>)

target_link_options(compile_options INTERFACE
                    $<$<CONFIG:Debug>:-fsanitize=address>)

add_subdirectory(src)

add_executable(mcc src/mcc.cpp)

set_target_properties(mcc PROPERTIES CXX_STANDARD 26 CXX_EXTENSIONS OFF)

target_include_directories(mcc PUBLIC ${CMAKE_BINARY_DIR}/src)
target_include_directories(mcc PUBLIC src)

target_link_libraries(mcc PRIVATE compile_options reflex parser)
