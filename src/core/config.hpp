#pragma once
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

namespace Nox{
    class Config{
    public:
        std::string             executable_name;
        std::filesystem::path   source_directory;
        std::filesystem::path   build_directory;
        std::string             compiler;
        std::string             compiler_version;
        std::string             cpp_version;

        bool create_file(const fs::path& path);
    };
}