#include <stdio.h>

int main() {
    int block_size[22], process_size[22], allocation[22];
    int num_blocks, num_processes;

    // Input number of blocks and their sizes
    printf("Enter the number of blocks:\n");
    scanf("%d", &num_blocks);
    printf("Enter the block sizes:\n");
    for (int i = 0; i < num_blocks; i++) {
        scanf("%d", &block_size[i]);
    }

    // Input number of processes and their sizes
    printf("Enter the number of processes:\n");
    scanf("%d", &num_processes);
    printf("Enter the process sizes:\n");
    for (int i = 0; i < num_processes; i++) {
        scanf("%d", &process_size[i]);
        allocation[i] = -1; // Initialize allocation as "not allocated"
    }

    // Best Fit Allocation
    for (int i = 0; i < num_processes; i++) {
        int best = -1;
        for (int j = 0; j < num_blocks; j++) {
            if (block_size[j] >= process_size[i] && 
                (best == -1 || block_size[j] < block_size[best])) {
                best = j; // Update best block index
            }
        }
        if (best != -1) {
            allocation[i] = best; // Allocate the block to the process
            block_size[best] -= process_size[i]; // Reduce the block size
        }
    }

    // Display allocation results
    printf("\nProcess\tSize\tBlock\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t", i + 1, process_size[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }

    return 0;
}
