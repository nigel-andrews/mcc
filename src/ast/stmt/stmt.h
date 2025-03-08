#pragma once

#include <memory>
#include <variant>

#include "ast/decl/decl.h"

namespace ast
{
    using Stmt = std::variant<std::unique_ptr<class ReturnStmt>>;

    using CompoundStmt = std::variant<Stmt, Decl>;
} // namespace ast
