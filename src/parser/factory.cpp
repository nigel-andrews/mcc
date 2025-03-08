#include "factory.h"

#include "ast/decl/fundec.h"
#include "ast/expr/int_expr.h"
#include "ast/stmt/return_stmt.h"

namespace ast::factory
{
    Node* make_int_expr(const parse::location& location, int val)
    {
        return new IntExpr(location, val);
    }

    Node* make_fundec(const parse::location& location, std::string_view name)
    {
        return new FunDec(location, name);
    }

    Node* make_return_stmt(const parse::location& location, Expr expr)
    {
        return new ReturnStmt(location, std::move(expr));
    }
} // namespace ast::factory
