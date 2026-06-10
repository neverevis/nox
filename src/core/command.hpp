#pragma once
#include <string>

namespace Nox{
    class Command{
    public:
        struct Result{
            bool success;
            std::string message = "";
        };
        Result create(const std::string& project_name);
        Result build();
        Result run();
    };
}