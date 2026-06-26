#include <core/command.hpp>

#include <filesystem>
#include <fstream>
#include <util/color.hpp>
#include <util/log.hpp>
#include <platform/process.hpp>

namespace fs = std::filesystem;
using c = Nox::Util::Color;
using Log = Nox::Util::Log;
using Process = Nox::Process;

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
        std::ofstream main(project / "config.toml");

        Log::println("{}[nox]{} creating config file",c::bright_green, c::bright_blue);
        Log::print("{}detecting compiler {}-> ",c::cyan, c::yellow);

        std::string compiler = "";
        std::string compiler_version = "";

        Process::Result clang   = Process::execute("clang++",{"-dumpversion"});
        Process::Result gcc     = Process::execute("g++",{"-dumpversion"});

        if(clang.exit_code == 0){
            Log::println("{}clang",c::bright_yellow);
            compiler = "clang";
            compiler_version = clang.output_text;
            
        }
        else if(gcc.exit_code == 0){
            Log::println("{}gcc",c::bright_yellow);
            compiler = "gcc";
            compiler_version = gcc.output_text;
        }

        Log::println("compiler version: {}", compiler_version);

        main << "language = c++\n";
        main << "version = 23\n";
        main << "compiler = clang\n";
        return true;
    }

    bool Command::create_sources(const fs::path& project){
        return true;
    }
}
