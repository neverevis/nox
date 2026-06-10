#pragma once
#include <string>
#include <filesystem>

namespace Nox{
    class Config{
    public:
        std::string executable_name;
        std::filesystem::path source_directory;
        std::filesystem::path build_directory;
        std::string cpp_version;
        std::string compiler;
        std::string modules;
    };
}