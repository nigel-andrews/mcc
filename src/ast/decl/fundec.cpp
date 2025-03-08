#include "fundec.h"

#include "ast/stmt/return_stmt.h"

namespace ast
{
    FunDec::FunDec(const parse::location& location, std::string_view name)
        : Node(location)
        , name_(name)
    {}

    FunDec::~FunDec() = default;
} // namespace ast
