#include <platform/platform.hpp>
#if defined(PLATFORM_WINDOWS)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <platform/process.hpp>

Nox::Process::Result Nox::Process::execute(const std::string& executable, std::vector<std::string>& arguments){
    Nox::Process::Result result;
    result.exit_code = -1;
    result.output_text = "";

    std::string command = executable;

    for(std::string& argument : arguments){
        command += " " + argument;
    }

    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;

    HANDLE h_read_pipe = nullptr;
    HANDLE h_write_pipe = nullptr;

    if(!CreatePipe(&h_read_pipe, &h_write_pipe, &saAttr, 0)){
        return result;
    }

    SetHandleInformation(h_read_pipe, HANDLE_FLAG_INHERIT, 0);

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(STARTUPINFOA));
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

    si.cb = sizeof(STARTUPINFOA);
    si.dwFlags |= STARTF_USESTDHANDLES;
    si.hStdOutput = h_write_pipe;
    si.hStdError = h_write_pipe;
    si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);

    BOOL success = CreateProcessA(nullptr, &command[0], nullptr, nullptr, TRUE, 0, nullptr, nullptr, &si, &pi);

    if(success){
        CloseHandle(h_write_pipe);

        char buffer[4096];
        DWORD bytes_read;

        while(ReadFile(h_read_pipe, buffer, sizeof(buffer) - 1, &bytes_read, nullptr)){
            buffer[bytes_read] = '\0';
            result.output_text += buffer;
        }

        WaitForSingleObject(pi.hProcess, INFINITE);

        DWORD exit_code;
        GetExitCodeProcess(pi.hProcess, &exit_code);
        result.exit_code = static_cast<int>(exit_code);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else {
        CloseHandle(h_write_pipe);
    }

    CloseHandle(h_read_pipe);

    return result;
}

#endif
