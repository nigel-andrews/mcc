#pragma once

#include <vector>

#include "ast/fwd.h"
#include "misc/symbol.h"

namespace ast
{
    class FunDec : Node
    {
    public:
        FunDec(const parse::location& loc, misc::symbol name)
            : Node(loc)
            , name_(name)
        {}

    private:
        misc::symbol name_;

        std::vector<StmtPtr> stmts_;

        // TODO: Function + return type
    };
} // namespace ast
