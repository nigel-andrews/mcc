#include "symbol.h"

namespace misc
{
    symbol::symbol(std::string_view s)
        : value_(&*set_instance().emplace(s).first)
    {}

    symbol::symbol(const char* s)
        : value_(&*set_instance().emplace(s).first)
    {}

    symbol::symbol(const std::string& s)
        : value_(&*set_instance().insert(s).first)
    {}

    const std::string& symbol::get()
    {
        return *value_;
    }

    std::unordered_set<std::string>& symbol::set_instance()
    {
        static std::unordered_set<std::string> set;

        return set;
    }

    symbol::operator const std::string&() const
    {
        return *value_;
    }

    symbol::operator const char*() const
    {
        return value_->c_str();
    }

    bool symbol::operator==(const std::string& other) const
    {
        return *value_ == other;
    }

    bool symbol::operator!=(const std::string& other) const
    {
        return *value_ != other;
    }

} // namespace misc
