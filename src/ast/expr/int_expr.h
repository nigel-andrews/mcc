#pragma once

#include "ast/node.h"

namespace ast
{
    class IntExpr : public Node
    {
    public:
        IntExpr(const parse::location& location, int value);
        ~IntExpr();

        int value_get();

    private:
        int value_;
    };
} // namespace ast
