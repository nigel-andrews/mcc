#pragma once

#include <memory>
#include <variant>

#include "ast/node.h"

namespace ast
{
    // Neither stmt nor expr
    class FunDec;

    // Expr
    class IntExpr;
    using Expr = std::variant<IntExpr>;

    // Stmt
    class ReturnStmt;
    using Stmt = std::variant<ReturnStmt>;

    // Only smart pointer allowing incomplete type is shared_ptr
    using StmtPtr = std::shared_ptr<Stmt>;
    using ExprPtr = std::shared_ptr<Expr>;

} // namespace ast
