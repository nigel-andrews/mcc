#pragma once

#include <any>

#include "ast/int_expr.h"
#include "ast/node.h"

namespace ast
{
    // FIXME: Need to declare what stmts are somewhere (ast fwd file)
    class ReturnStmt : Node
    {
    public:
        ReturnStmt(const yy::location& loc)
            : Node(loc)
        {}

    private:
        std::optional<IntExpr> expr_;
    };
} // namespace ast
