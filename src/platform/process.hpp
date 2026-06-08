#pragma once
#include <string>
#include <vector>

namespace Nox{
    class Process{
    public:
        struct Result{
            int         exit_code;
            std::string output_text;
        };

        static Result execute(const std::string& executable, std::vector<std::string>& arguments);
    };
}
