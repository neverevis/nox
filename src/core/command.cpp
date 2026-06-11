#include <core/command.hpp>

#include <filesystem>
#include <fstream>
#include <util/color.hpp>

namespace fs = std::filesystem;
using c = Nox::Util::Color;

namespace Nox{
    Command::Result Command::create(fs::path project){
        Result result;

        if(!create_directories(project)){
            result.success = false;
            result.message = "failed to create project directory";
            return result;
        }

        if(!create_config(project)){
            result.success = false;
            result.message = "failed to create project config";
            return result;
        }

        if(!create_sources(project)){
            result.success = false;
            result.message = "failed to create project source";
            return result;
        }

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

    bool Command::create_directories(const fs::path& project){
        bool result = true;
        result &= fs::create_directory(project);
        result &= fs::create_directory(project / ".nox");
        result &= fs::create_directory(project / ".nox" / "includes");
        result &= fs::create_directory(project / "src");
        result &= fs::create_directory(project / "build");

        return result;
    }

    bool Command::create_config(const fs::path& project){
        return true;
    }

    bool Command::create_sources(const fs::path& project){
        return true;
    }
}
