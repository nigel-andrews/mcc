#include "context.h"

#include <fstream>

namespace parse
{
    ParserContext::ParserContext(std::ifstream& source)
        : input_(source)
        , lexer_(input_)
        , parser_(lexer_)
    {}

    int ParserContext::parse()
    {
        return parser_.parse();
    }
} // namespace parse
