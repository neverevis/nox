#pragma once
#include <string_view>
#include <format>
#include <iostream>
#include <cstdio>

namespace Nox::Util{
    class Log{
    public:
        template<typename... Args>
        static void println(std::format_string<Args...> fmt, Args&&... args){
            std::cout << std::format(fmt, std::forward<Args>(args)...) << std::endl;
        }
    };
}