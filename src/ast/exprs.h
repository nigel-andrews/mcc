#pragma once

#include <variant>

#include "ast_base.h"

namespace ast
{
    class IntLiteral : public AstBase
    {
    public:
        IntLiteral(yy::location location, int value)
            : AstBase(std::move(location))
            , value_(value)
        {}

        int value_get() const
        {
            return value_;
        }

    private:
        int value_;
    };

    using Expr = std::variant<IntLiteral>;
} // namespace ast
