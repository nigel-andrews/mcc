#include <format>
#include <fstream>
#include <iostream>

#include "ast/fwd.h"
#include "parser/context.h"

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

    parse::ParserContext ctx(source);
    ctx.debug_trace_set(true);

    return ctx.parse();
}
