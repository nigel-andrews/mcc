#pragma once

#include <memory>
#include <variant>

namespace ast
{
    using Expr = std::variant<std::unique_ptr<class IntExpr>>;
} // namespace ast
