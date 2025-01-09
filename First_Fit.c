#include <stdio.h>
int main() {
    int block_size[22], process_size[22], allocation[22], numblocks, numprocess;

    // Input block details
    printf("Enter the number of blocks:\n");
    scanf("%d", &numblocks);
    printf("Enter the size of blocks:\n");
    for (int i = 0; i < numblocks; i++) {
        scanf("%d", &block_size[i]);
    }

    // Input process details
    printf("Enter the number of processes:\n");
    scanf("%d", &numprocess);
    printf("Enter the size of processes:\n");
    for (int i = 0; i < numprocess; i++) {
        scanf("%d", &process_size[i]);
        allocation[i] = -1; // Initialize all allocations as -1 (not allocated)
    }

    // First-Fit Allocation
    for (int i = 0; i < numprocess; i++) {
        for (int j = 0; j < numblocks; j++) {
            if (block_size[j] >= process_size[i]) { // If block can accommodate process
                allocation[i] = j;                // Allocate block to process
                block_size[j] -= process_size[i]; // Reduce block size
                break;                            // Move to the next process
            }
        }
    }

    // Display allocation results
    printf("Process\tSize\tBlock\n");
    for (int i = 0; i < numprocess; i++) {
        printf("%d\t%d\t", i + 1, process_size[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1); // Print allocated block (1-based index)
        } else {
            printf("Not allocated\n");
        }
    }

    return 0;
}
