#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER 25

int main() {
    int pipe_fd[2];
    pid_t pid;
    char message[BUFFER] = "Hello World";

    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        close(pipe_fd[1]); // Close the write end
        char buff[BUFFER];
        ssize_t bytesRead = read(pipe_fd[0], buff, BUFFER);
        if (bytesRead == -1) {
            perror("Read failed");
            return 1;
        }
        close(pipe_fd[0]); // Close the read end
        printf("Child Read: %s\n", buff);
        return 0;
    } else {
        // Parent process
        close(pipe_fd[0]); // Close the read end
        ssize_t bytesWritten = write(pipe_fd[1], message, BUFFER);
        if (bytesWritten == -1) {
            perror("Write failed");
            return 1;
        }
        close(pipe_fd[1]); // Close the write end
        wait(NULL); // Wait for the child to complete
        return 0;
    }
}
