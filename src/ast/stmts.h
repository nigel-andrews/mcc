#pragma once

#include <variant>
#include <vector>

#include "ast_base.h"
#include "exprs.h"

namespace ast
{
    class ExprStmt : public AstBase
    {
    public:
        ExprStmt(yy::location location, Expr expression)
            : AstBase(std::move(location))
            , expression_(expression)
        {}

    private:
        Expr expression_;
    };

    class ReturnStmt : public AstBase
    {
    public:
        ReturnStmt(yy::location location, Expr expr)
            : AstBase(std::move(location))
            , return_expr_(std::move(expr))
        {}

    private:
        Expr return_expr_;
    };

    class CompoundStmt;

    using Stmt = std::variant<CompoundStmt, ReturnStmt, ExprStmt>;

    class CompoundStmt : public AstBase
    {
    public:
        CompoundStmt(yy::location location)
            : AstBase(std::move(location))
            , statements_()
        {}

    private:
        std::vector<Stmt> statements_;
    };
} // namespace ast
