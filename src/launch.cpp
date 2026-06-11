#include <platform/process.hpp>

#include <util/color.hpp>
#include <util/log.hpp>
#include <core/command.hpp>
#include <platform/process.hpp>

using Color = Nox::Util::Color;
using Log = Nox::Util::Log;

int main(int argc, char** argv)
{
    if(argc < 2){
        Log::println("Use: {}nox {}[{}create {}| {}build {}| {}run{}]",Color::yellow, Color::white, Color::bright_green, Color::white, Color::bright_green, Color::white, Color::bright_green, Color::white);

        return -1;
    }

    std::string action = argv[1];

    Nox::Command command;

    if(action == "create"){
        if(argc < 3){
            Log::println("{}Project must have a {}name!\n{}Use: {}nox {}create {}\"project_name\"",Color::white, Color::cyan, Color::white, Color::bright_green, Color::white, Color::blue);
            return -1;
        }

        Nox::Command::Result rs = command.create(argv[2]);

        printf("%s", rs.message.c_str());
    }

    else if(action == "build"){
        command.build();
    }

    else if(action == "run"){
        command.run();
    }

    else if(action == "--version"){
        std::cout << "nox 0.0.1" << std::endl;
    }
    else{
        std::cout << Color::purple << "[nox] " << Color::red << "unknown command" << Color::white << std::endl;
    }
}
