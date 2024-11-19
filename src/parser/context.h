#pragma once

namespace parse
{
    class ParserContext;
};

#include "parser/generator/lex.yy.h"
#include "parser/generator/location.h"
#include "parser/generator/parser.hpp"

namespace parse
{
    class ParserContext
    {
    public:
        ParserContext(std::ifstream& source);

        int parse();

        void debug_trace_set(bool value);

    private:
        reflex::Input input_;
        Lexer lexer_;
        Parser parser_;
        location location_;

        bool debug_trace_;
    };

} // namespace parse
