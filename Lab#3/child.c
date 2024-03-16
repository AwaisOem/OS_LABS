#include <stdio.h>
#include <unistd.h>

#define BUFFER 25

int main() {
    int pipe_fd[2];
    char buff[BUFFER];

    if (read(0, buff, BUFFER) == -1) {
        perror("Read failed");
        return 1;
    }

    printf("Child Read: %s\n", buff);
    return 0;
}
