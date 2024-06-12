#pragma once

#include "decls.h"

namespace ast
{
    struct TranslationUnitDecl : public AstBase
    {
        // Technically should be a vector of external declarations, but this
        // can be factorized into a vector of Declaration where function
        // definitions are simply function declarations that have bodies
        // This might be a horrible way of handling this especially when
        // checking for multiple definitions but for now why not
        std::vector<Decl> external_decls_;
    };
} // namespace ast
