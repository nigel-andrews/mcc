#pragma once

#include "ast/expr/expr.h"
#include "ast/node.h"

namespace ast
{
    class ReturnStmt : public Node
    {
    public:
        ReturnStmt(const parse::location& location, Expr expr);
        ~ReturnStmt();

    private:
        Expr expr_;
    };
} // namespace ast
