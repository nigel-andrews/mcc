#pragma once

namespace misc
{
    template <typename T>
    class Singleton
    {
        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;

        Singleton& operator=(const Singleton&) = delete;
        Singleton& operator=(Singleton&&) = delete;

    protected:
        constexpr T& get_instance()
        {
            static T instance;

            return instance;
        }

        constexpr Singleton() = default;
        constexpr ~Singleton() = default;
    };
}; // namespace misc
