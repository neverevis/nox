#include <print>
#include <vector>
#include <string>
#include <platform/process.hpp>
#include <util/color.hpp>

using Color = Nox::Util::Color;

int main(int argc, char** argv)
{
    if(argc < 2){
        std::println("{}Use:{} lux{} [{}create{} | {}build{} | {}run{}]",Color::white, Color::blue, Color::white, Color::yellow, Color::white, Color::yellow, Color::white, Color::yellow, Color::white);
        return -1;
    }

    std::string command = argv[1];

    if(command == "create"){
        std::println("{}[nox] {}creating project{} ",Color::purple, Color::green, Color::white);
    }
    else if(command == "build"){
        std::println("{}[nox] {}building project{} ",Color::yellow, Color::green, Color::white);
    }
    else if(command == "run"){
        std::println("{}[nox] {}running project{} ",Color::purple, Color::green, Color::white);
    }
    else if(command == "--version"){
        std::println("nox 0.0.1 (windows-x86-64)");
    }
    else{
        std::println("{}[nox]{} unknown command{}",Color::green, Color::red, Color::white);
    }
}
