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

        static constexpr std::string_view bright_black  = "\033[0;90m";
        static constexpr std::string_view bright_red    = "\033[0;91m";
        static constexpr std::string_view bright_green  = "\033[0;92m";
        static constexpr std::string_view bright_yellow = "\033[0;93m";
        static constexpr std::string_view bright_blue   = "\033[0;94m";
        static constexpr std::string_view bright_magenta= "\033[0;95m";
        static constexpr std::string_view bright_cyan   = "\033[0;96m";
        static constexpr std::string_view bright_white  = "\033[0;97m";
    };
}
