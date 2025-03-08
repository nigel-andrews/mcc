#pragma once

#include <vector>

#include "ast/node.h"
#include "ast/stmt/stmt.h"
#include "misc/symbol.h"

namespace ast
{
    class FunDec : public Node
    {
    public:
        FunDec(const parse::location& location, std::string_view name);
        ~FunDec();

    private:
        misc::symbol name_;
        std::vector<CompoundStmt> body_;
    };
} // namespace ast
