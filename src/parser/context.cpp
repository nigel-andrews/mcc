#include "context.h"

#include <fstream>

namespace parse
{
    ParserContext::ParserContext(std::ifstream& source)
        : input_(source)
        , lexer_(input_)
        , parser_(lexer_)
    {}

    void ParserContext::parse()
    {
        parser_.parse();
    }
} // namespace parse
