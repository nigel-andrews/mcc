#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include <unordered_set>

namespace misc
{
    class symbol
    {
    public:
        symbol(const char* s = "");
        symbol(const std::string& s);

        const std::string& get();
        operator const std::string&();

    private:
        std::unordered_set<std::string>& set_instance();

        const std::string* value_;
    };
} // namespace misc

#endif /* ! SYMBOL_H */