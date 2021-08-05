#ifndef SPECIALIZATIONS_HH
#define SPECIALIZATIONS_HH 1

///@file specializations.hh A file containing specializations of standard library functions

#include <utility>
#include <string>

namespace std
{
    template<>
    struct hash<std::pair<std::string, int>> 
    {
        size_t operator()(const std::pair<std::string, int>& p) const noexcept
        {
            size_t seed = hash<int>{}(p.second);
            seed ^= hash<std::string>{}(p.first) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
} // namespace name



#endif