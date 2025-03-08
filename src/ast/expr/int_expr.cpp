#include "int_expr.h"

namespace ast
{
    IntExpr::IntExpr(const parse::location& location, int value)
        : Node(location)
        , value_(value)
    {}

    IntExpr::~IntExpr() = default;

    int IntExpr::value_get()
    {
        return value_;
    }
} // namespace ast
