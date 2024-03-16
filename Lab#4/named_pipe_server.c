#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define THE_PIPE "/tmp/testpipe"

int main() {
    int pipe_fd;
    char buf[100];
    ssize_t bytes_read;

    if (mkfifo(THE_PIPE, 0666) == -1) {
        perror("mkfifo failed");
        exit(1);
    }

    printf("Waiting for the pipe...\n");

    pipe_fd = open(THE_PIPE, O_RDWR);
    if (pipe_fd == -1) {
        perror("open failed");
        exit(1);
    }

    printf("The pipe is ready\n");

    for (int i = 0; i < 5; i++) {
        bytes_read = read(pipe_fd, buf, sizeof(buf) - 1);
        if (bytes_read == -1) {
            perror("read failed");
            break;
        }

        buf[bytes_read] = '\0';
        printf("Read: [%s]\n", buf);
    }

    sprintf(buf, "Bye");
    printf("Sending: [%s]\n", buf);

    if (write(pipe_fd, buf, sizeof(buf)) == -1) {
        perror("write failed");
    }

    close(pipe_fd);
    unlink(THE_PIPE);

    return 0;
}
