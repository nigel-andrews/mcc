add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp
         ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.h
  COMMAND ${REFLEX} ${CMAKE_CURRENT_SOURCE_DIR}/lexer.lxx --header-file
          --bison-complete --lexer=Lexer
  DEPENDS ${REFLEX} ${CMAKE_CURRENT_SOURCE_DIR}/lexer.lxx
  COMMENT "Generating lexer files")

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
  COMMAND ${BISON} ${CMAKE_CURRENT_SOURCE_DIR}/parser.yxx
  DEPENDS ${BISON} ${CMAKE_CURRENT_SOURCE_DIR/parser.yxx}
          ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.h
  COMMENT "Generating parser")

add_library(generator STATIC ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp
                             ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)

set_target_properties(generator PROPERTIES CXX_STANDARD 23 CXX_EXTENSIONS OFF)

find_path(REFLEX_PATH reflex)
target_compile_options(generator PRIVATE "-I${REFLEX_PATH}")

target_include_directories(generator PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(generator PRIVATE compile_options reflex_shared_lib misc)
