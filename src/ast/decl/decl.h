#pragma once

#include <memory>
#include <variant>

namespace ast
{
    using Decl = std::variant<std::unique_ptr<class FunDec>>;
} // namespace ast
