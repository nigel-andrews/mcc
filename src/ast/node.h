#pragma once

#include "parser/location.h"

namespace ast
{
    class Node
    {
    public:
        Node(const parse::location& loc)
            : loc_(loc)
        {}

        virtual ~Node() = default;

        const parse::location& loc_get()
        {
            return loc_;
        }

    private:
        parse::location loc_;
    };
} // namespace ast
