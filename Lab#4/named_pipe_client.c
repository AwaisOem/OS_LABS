#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define THE_PIPE "/tmp/testpipe"

int main() {
    int pipe_fd;
    char buf[1024];
    ssize_t bytes_written, bytes_read;

    printf("Waiting for the pipe...\n");

    if (access(THE_PIPE, F_OK) == -1) {
        perror("access failed");
        return 1;
    }

    pipe_fd = open(THE_PIPE, O_RDWR);
    if (pipe_fd == -1) {
        perror("open failed");
        return 1;
    }

    printf("The pipe is ready\n");

    for (int i = 0; i < 5; i++) {
        sprintf(buf, "This is test line %d so there.", i);
        printf("Sending: [%s]\n", buf);

        bytes_written = write(pipe_fd, buf, strlen(buf));
        if (bytes_written == -1) {
            perror("write failed");
            break;
        }
    }

    bytes_read = read(pipe_fd, buf, sizeof(buf) - 1);
    if (bytes_read == -1) {
        perror("read failed");
    } else {
        buf[bytes_read] = '\0';
        printf("%s\n", buf);
    }

    close(pipe_fd);

    return 0;
}
