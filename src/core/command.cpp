#include <core/command.hpp>

#include <filesystem>
#include <fstream>
#include <util/color.hpp>

namespace fs = std::filesystem;
using c = Nox::Util::Color;

namespace Nox{
    Command::Result Command::create(const std::string& project_name){
        Result result;

        fs::path project(project_name);

        if(!fs::create_directory(project)){
            result.message = std::string(project_name + " already exists");
            result.success = false;
        }

        fs::path dot_nox(project / ".nox");
        fs::path source(project / "src");
        fs::path build(project / "build");

        
        return result;
    }

    Command::Result Command::build(){
        Result result;
        return result;
    }

    Command::Result Command::run(){
        Result result;
        return result;
    }
}
