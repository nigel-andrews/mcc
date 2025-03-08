#pragma once

#include <memory>
#include <variant>
#include <vector>

#include "ast/decl/decl.h"

namespace ast
{
    using Stmt = std::variant<std::unique_ptr<class ReturnStmt>>;

    using BlockItem = std::variant<Stmt, Decl>;
    using CompoundStmt = std::vector<BlockItem>;
} // namespace ast
