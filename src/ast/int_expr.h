#pragma once

#include "ast/node.h"

namespace ast
{
    class IntExpr : Node
    {
    public:
        IntExpr(const yy::location& loc, int val)
            : Node(loc)
            , val_(val)
        {}

        int val_get()
        {
            return val_;
        }

    private:
        int val_;
    };
} // namespace ast
