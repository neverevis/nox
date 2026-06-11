#pragma once
#include <string>
#include <filesystem>

namespace Nox{
    class Command{
    public:
        struct Result{
            bool success;
            std::string message = "";
        };

        Result create(std::filesystem::path project);
        Result build();
        Result run();

    private:
        bool create_directories(const std::filesystem::path& project);
        bool create_config(const std::filesystem::path& project);
        bool create_sources(const std::filesystem::path& project);
    };
}