#include <core/command.hpp>

#include <filesystem>
#include <fstream>
#include <util/color.hpp>
#include <util/log.hpp>
#include <core/config.hpp>
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
        result &= fs::create_directory(project / ".nox" / "libs");
        result &= fs::create_directory(project / "src");
        result &= fs::create_directory(project / "build");

        return result;
    }

    bool Command::create_config(const fs::path& project){
        Config config;

        Log::println("{}[nox]{} creating config file",c::bright_green, c::bright_blue);

        detect_compiler(config.compiler, config.compiler_version);

        Log::println("{}detected compiler{}-> {}{} ",c::bright_cyan, c::yellow, c::red, config.compiler);
        Log::println("{}compiler version{}-> {}{}",c::bright_cyan, c::yellow, c::bright_blue, config.compiler_version);

        config.cpp_version = "23";
        config.executable_name = "program";
        config.build_directory = project / "build";
        config.source_directory = project / "src";

        return config.create_file(project);
    }

    bool Command::create_sources(const fs::path& project){
        return true;
    }

    void Command::detect_compiler(std::string& compiler, std::string& compiler_version){
        Process::Result clang   = Process::execute("clang",{"-dumpversion"});
        Process::Result gcc     = Process::execute("gcc",{"-dumpversion"});

        if(clang.exit_code == 0){
            compiler = "clang";
            compiler_version = clang.output_text;

        }
        else if(gcc.exit_code == 0){
            compiler = "gcc";
            compiler_version = gcc.output_text;
        }
        else{
            compiler = "none";
            compiler_version = "none";
        }
    }
}
