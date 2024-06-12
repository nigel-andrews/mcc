#pragma once

#include <optional>
#include <variant>

#include "ast/stmts.h"

namespace ast
{
    class FuncDecl : public AstBase
    {
    public:
        FuncDecl(yy::location location, std::string identifier)
            : AstBase(std::move(location))
            , is_main_(identifier == "main")
            , identifier_(identifier)
        {}

        FuncDecl(yy::location location, std::string identifier,
                 CompoundStmt body)
            : AstBase(std::move(location))
            , is_main_(identifier == "main")
            , identifier_(identifier)
            , body_(std::move(body))
        {}

    private:
        // TODO: direct-declarators
        bool is_main_;
        std::string identifier_;
        std::optional<CompoundStmt> body_;
    };

    struct VarDecl
    {};

    using Decl = std::variant<VarDecl, FuncDecl>;
} // namespace ast
