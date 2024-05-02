find_program(REFLEX reflex DOC "Path to RE/flex C++ lexical analyser generator.")
find_program(BISON bison DOC "Path to GNU Bison C/C++ parser generator.")

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp
  COMMAND ${REFLEX} ${CMAKE_CURRENT_SOURCE_DIR}/lexer.lxx
  --header-file --bison-complete --lexer=Lexer
  DEPENDS ${REFLEX} ${CMAKE_CURRENT_SOURCE_DIR}/lexer.lxx)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
  COMMAND ${BISON} ${CMAKE_CURRENT_SOURCE_DIR}/parser.yxx
  DEPENDS ${BISON} ${CMAKE_CURRENT_SOURCE_DIR/parser.yxx}
)

add_library(parser STATIC
  ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
)

target_link_libraries(parser PRIVATE reflex)
