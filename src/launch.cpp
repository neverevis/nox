#include <iostream>
#include <vector>
#include <string>
#include <platform/process.hpp>
#include <util/color.hpp>
#include <filesystem>

#include <platform/process.hpp>

using Color = Nox::Util::Color;

int main(int argc, char** argv)
{
    if(argc < 2){
        std::cout << "Use: " <<
        Color::bright_yellow <<
        "nox " <<
        Color::white <<
        "[" <<
        Color::bright_green <<
        "create" <<
        Color::white <<
        " |" <<
        Color::bright_green <<
        " build" <<
        Color::white <<
        " |" <<
        Color::bright_green <<
        "run" <<
        Color::white <<
        "]" <<
        std::endl;

        return -1;
    }

    std::string command = argv[1];

    if(command == "create"){
        std::cout << Color::purple << "[nox] " << Color::green << "creating project" << Color::white << std::endl;
    }
    else if(command == "build"){
        std::cout << Color::purple << "[nox] " << Color::green << "building project" << Color::white << std::endl;
    }
    else if(command == "run"){
        std::cout << Color::purple << "[nox] " << Color::green << "running project" << Color::white << std::endl;
    }
    else if(command == "--version"){
        std::cout << "nox 0.0.1" << std::endl;
    }
    else{
        std::cout << Color::purple << "[nox] " << Color::red << "unknown command" << Color::white << std::endl;
    }

    Nox::Process::Result rs = Nox::Process::execute("gcc",{"--version"});

    std::cout << rs.output_text;
}
