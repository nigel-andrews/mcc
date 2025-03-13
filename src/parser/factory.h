#pragma once

#include <string_view>

#include "ast/fwd.h"

namespace parse
{
    class location;
}

namespace ast::factory
{
    IntExpr* make_int_expr(const parse::location& location, int val);
    FunDec* make_fundec(const parse::location& location, std::string_view name);
    ReturnStmt* make_return_stmt(const parse::location& location, Expr* expr);
} // namespace ast::factory
