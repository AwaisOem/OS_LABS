#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed");
        return -1;
    } else if (pid == 0) {
        // Child process
        execlp("spotify", "spotify", NULL);
        fprintf(stderr, "Exec failed");
        return -1;
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        printf("Child Complete\n");
    }

    return 0;
}
