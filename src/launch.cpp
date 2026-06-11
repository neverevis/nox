#include <iostream>
#include <string>
#include <platform/process.hpp>
#include <util/color.hpp>
#include <core/command.hpp>

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
        " run" <<
        Color::white <<
        "]" <<
        std::endl;

        return -1;
    }

    std::string command = argv[1];

    Nox::Command cmd;

    if(command == "create"){
        if(argc < 3){
            printf("project must have a name");
            return -1;
        }
        Nox::Command::Result rs = cmd.create(std::string(argv[2]));
        printf("%s",rs.message.c_str());
    }
    else if(command == "build"){
        cmd.build();
    }
    else if(command == "run"){
        cmd.run();
    }
    else if(command == "--version"){
        std::cout << "nox 0.0.1" << std::endl;
    }
    else{
        std::cout << Color::purple << "[nox] " << Color::red << "unknown command" << Color::white << std::endl;
    }
}
