find_program(REFLEX reflex DOC "Path to reflex lexical analyser generator.")

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp
  COMMAND ${REFLEX} ${CMAKE_CURRENT_SOURCE_DIR}/lexer.l
          --header-file=${CMAKE_CURRENT_BINARY_DIR}/lexer.h
  DEPENDS ${REFLEX} ${CMAKE_CURRENT_SOURCE_DIR}/lexer.l)

add_library(parser STATIC ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp)

target_link_libraries(parser PRIVATE reflex)
