cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 23)

project(mcc LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_program(REFLEX reflex
             DOC "Path to RE/flex C++ lexical analyser generator.")
if(NOT REFLEX)
  message(FATAL_ERROR "RE/Flex not found")
endif()

find_program(BISON bison DOC "Path to GNU Bison C/C++ parser generator.")
if(NOT BISON)
  message(FATAL_ERROR "Bison not found")
endif()

find_package(GTest)

add_library(compile_options INTERFACE)

target_compile_options(
  compile_options
  INTERFACE "-Wall"
            "-Wextra"
            "-pedantic"
            $<$<CONFIG:Release>:-O3>
            $<$<CONFIG:Release>:-Werror>
            $<$<CONFIG:Debug>:-O0>
            $<$<CONFIG:Debug>:-fno-inline>
            $<$<CONFIG:Debug>:-g3>
            $<$<CONFIG:Debug>:-fsanitize=address>)

target_link_options(compile_options INTERFACE
                    $<$<CONFIG:Debug>:-fsanitize=address>)

target_include_directories(compile_options INTERFACE ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(mcc src/mcc.cpp)

set_target_properties(mcc PROPERTIES CXX_STANDARD 23 CXX_EXTENSIONS OFF)

target_include_directories(mcc PUBLIC ${CMAKE_BINARY_DIR}/src)

# Include directories doesn't work because .... ?
find_path(REFLEX_PATH reflex)
target_compile_options(mcc PRIVATE "-I${REFLEX_PATH}")

target_link_libraries(mcc PRIVATE compile_options reflex_shared_lib parser misc)
