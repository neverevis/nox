#include <platform/platform.hpp>
#if defined(PLATFORM_LINUX)

#include <platform/process.hpp>
#include <spawn.h>
#include <sys/wait.h>

extern char **environ;

Nox::Process::Result Nox::Process::execute(const std::string& executable, const std::vector<std::string>& arguments){
    Nox::Process::Result result;
    result.exit_code = -1;
    result.output_text = "";

    int pipefd[2];
    pipe(pipefd);

    posix_spawn_file_actions_t actions;
    posix_spawn_file_actions_init(&actions);

    posix_spawn_file_actions_adddup2(&actions, pipefd[1], STDOUT_FILENO);
    posix_spawn_file_actions_adddup2(&actions, pipefd[1], STDERR_FILENO);
    posix_spawn_file_actions_addclose(&actions, pipefd[0]);

    pid_t pid;

    std::vector<char*> argv;
    argv.push_back(const_cast<char*>(executable.c_str()));

    for (auto& arg : arguments) {
        argv.push_back(const_cast<char*>(arg.c_str()));
    }

    argv.push_back(nullptr);

    int spawn_result = posix_spawnp(&pid, executable.c_str(), &actions, nullptr, argv.data(), environ);

    if(spawn_result != 0){
        close(pipefd[0]);
        posix_spawn_file_actions_destroy(&actions);
        return result;
    }

    close(pipefd[1]);

    char buffer[4096];
    ssize_t n;

    while ((n = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
        result.output_text.append(buffer, n);
    }

    close(pipefd[0]);

    int status;
    waitpid(pid, &status, 0);

    if (WIFEXITED(status))
        result.exit_code = WEXITSTATUS(status);

    posix_spawn_file_actions_destroy(&actions);

    return result;
}

#endif
