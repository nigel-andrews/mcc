#pragma once

#include "ast/fwd.h"

namespace ast
{
    class ReturnStmt : Node
    {
    public:
        ReturnStmt(const parse::location& loc)
            : Node(loc)
        {}

    private:
        ExprPtr expr_;
    };
} // namespace ast
