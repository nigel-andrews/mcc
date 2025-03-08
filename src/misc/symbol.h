#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include <unordered_set>

namespace misc
{
    class symbol
    {
    public:
        symbol(std::string_view);
        symbol(const char* s = "");
        symbol(const std::string& s);

        const std::string& get();

        operator const std::string&() const;
        operator const char*() const;

        bool operator==(const std::string& other) const;
        bool operator!=(const std::string& other) const;

    private:
        std::unordered_set<std::string>& set_instance();

    private:
        const std::string* value_;
    };
} // namespace misc

#endif /* ! SYMBOL_H */
