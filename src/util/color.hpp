#pragma once
#include <string_view>

namespace Nox::Util{
    struct Color{
        static constexpr std::string_view black = "\e[0;30m";
        static constexpr std::string_view red = "\e[0;31m";
        static constexpr std::string_view green = "\e[0;32m";
        static constexpr std::string_view yellow = "\e[0;33m";
        static constexpr std::string_view blue = "\e[0;34m";
        static constexpr std::string_view purple = "\e[0;35m";
        static constexpr std::string_view cyan = "\e[0;36m";
        static constexpr std::string_view white = "\e[0;37m";
    };
}
