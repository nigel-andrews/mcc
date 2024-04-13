#include <fstream>
#include <iostream>

#include "parser/lexer.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage : mcc <source C file>";
        return 1;
    }

    auto source = std::ifstream(argv[1]);
    reflex::Input lexer_input(source);

    auto ret = Lexer(lexer_input).lex();

    return ret;
}
