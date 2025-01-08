#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    key_t key = ftok(".", 's');                  // Generate key
    int shm_id = shmget(key, SIZE, IPC_CREAT | 0666);  // Create shared memory
    char *shared_memory = (char *)shmat(shm_id, NULL, 0); // Attach memory

    // Write to shared memory
    strcpy(shared_memory, "Hello, Shared Memory!");
    printf("Data written: %s\n", shared_memory);

    // Read from shared memory
    printf("Data read: %s\n", shared_memory);

    // Cleanup
    shmdt(shared_memory);           // Detach
    shmctl(shm_id, IPC_RMID, NULL); // Remove
    printf("Shared memory cleaned up.\n");

    return 0;
}
