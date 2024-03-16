#include <stdio.h>
#include <pthread.h>

// Function to be executed by the first thread
void* ThreadFunction1(void* arg) {
    printf("Thread 1: Hello from Thread 1!\n");
    return NULL;
}

// Function to be executed by the second thread
void* ThreadFunction2(void* arg) {
    printf("Thread 2: Hello from Thread 2!\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create the first thread
    if (pthread_create(&thread1, NULL, ThreadFunction1, NULL) != 0) {
        fprintf(stderr, "Error creating Thread 1\n");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL, ThreadFunction2, NULL) != 0) {
        fprintf(stderr, "Error creating Thread 2\n");
        return 1;
    }

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
