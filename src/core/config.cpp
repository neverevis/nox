#include <core/config.hpp>
#include <fstream>

namespace Nox{
    bool Config::create_file(const fs::path& path){
        std::ofstream file(path / "config.toml");

        if(!file.is_open()){
            return false;
        }

        file << "executable_name = "    << executable_name                      << "\n";
        file << "source_directory = "   << source_directory.filename().string() << "\n";
        file << "build_directory = "    << build_directory.filename().string()  << "\n";
        file << "compiler = "           << compiler                             << "\n";
        file << "compiler_version = "   << compiler_version                     << "\n";
        file << "cpp_version = "        << cpp_version                          << "\n";

        return file.good();
    }
}
