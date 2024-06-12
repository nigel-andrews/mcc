#pragma once

#include <utility>

#include "parser/location.h"

namespace ast
{
    class AstBase
    {
    public:
        constexpr auto&& location_get(this auto&& self)
        {
            return std::forward(self).location_;
        }

        template <typename Self>
        void* codeGen(this Self&& self)
        {
            auto derived = self;

            return self.codeGen();
        }

    protected:
        // FIXME: Check generated make_NODE functions to see if copy ellision is
        // possible or take by const-ref and copy construct
        explicit AstBase(yy::location location)
            : location_(std::move(location))
        {}

    private:
        yy::location location_;
    };
} // namespace ast
