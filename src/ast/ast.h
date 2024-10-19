#pragma once

#include "parser/location.h"

namespace ast
{
    class Node
    {
    public:
        Node(const yy::location& loc)
            : loc_(loc)
        {}

        virtual ~Node() = default;

        const yy::location& loc_get()
        {
            return loc_;
        }

    private:
        yy::location loc_;
    };
} // namespace ast
