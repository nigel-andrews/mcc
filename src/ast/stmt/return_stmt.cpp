#include "return_stmt.h"

#include "ast/expr/int_expr.h"

namespace ast
{
    ReturnStmt::ReturnStmt(const parse::location& location, Expr expr)
        : Node(location)
        , expr_(std::move(expr))
    {}

    ReturnStmt::~ReturnStmt() = default;
} // namespace ast
