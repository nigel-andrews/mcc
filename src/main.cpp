#include <format>
#include <fstream>
#include <iostream>

#include "parser/lexer.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage : mcc <source C file>\n";
        return 1;
    }

    auto source = std::ifstream(argv[1]);
    if (!source)
    {
        std::cerr << std::format("Unable to open file : {}\n", argv[1]);
    }
    reflex::Input lexer_input(source);

    auto ret = Lexer(lexer_input, std::cout).lex();

    return ret;
}
