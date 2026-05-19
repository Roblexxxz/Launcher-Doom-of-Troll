#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Launcher for Doom-of-Troll (DuneDash)
    
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process - execute DuneDash from submodule
        chdir("Doom-of-Troll");
        execvp("./Doom-of-Troll", argv);
        perror("execvp failed");
        exit(1);
    } else if (pid > 0) {
        // Parent process - wait for child
        int status;
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    } else {
        perror("fork failed");
        return 1;
    }
}
