#include <stdio.h>
#include <unistd.h> // For fork() and getpid()
#include <stdlib.h> // For exit()

int main() {
    int pid; // Variable to hold the process ID

    // Create a new process
    pid = fork();

    // Check if fork failed
    if (pid == -1) {
        printf("ERROR: Process creation failed.\n");
        exit(1); // Exit the program with an error code
    }

    if (pid != 0) {
        // Parent process (pid is non-zero for the parent)
        printf("The parent process ID is %d\n", getpid());
    } else {
        // Child process (pid is zero for the child)
        printf("The child process ID is %d\n", getpid());
    }

    return 0; // End of the program
}
