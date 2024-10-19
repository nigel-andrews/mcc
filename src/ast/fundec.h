#pragma once

#include <vector>

#include "ast/node.h"
#include "ast/return_stmt.h"
#include "misc/symbol.h"

namespace ast
{
    class FunDec : Node
    {
    public:
        FunDec(const yy::location& loc, misc::symbol name)
            : Node(loc)
            , name_(name)
        {}

    private:
        misc::symbol name_;

        // FIXME: Compound statements
        std::vector<ReturnStmt> stmts_;

        // TODO: Function + return type
    };
} // namespace ast
