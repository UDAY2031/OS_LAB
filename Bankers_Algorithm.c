#include <stdio.h>

int main() {
    int p, r; // Number of processes and resources
    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &p, &r);

    int allocation[p][r], max[p][r], need[p][r];
    int available[r], safe[p], done[p];
    int count = 0;

    // Input allocation matrix
    printf("Enter the allocation matrix (%dx%d):\n", p, r);
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &allocation[i][j]);

    // Input max matrix
    printf("Enter the max matrix (%dx%d):\n", p, r);
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    // Input available resources
    printf("Enter the available resources (%d):\n", r);
    for (int i = 0; i < r; i++)
        scanf("%d", &available[i]);

    // Calculate the need matrix
    printf("\nNeed matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Initialize process status
    for (int i = 0; i < p; i++)
        done[i] = 0;

    // Safety algorithm
    while (count < p) {
        int found = 0; // Flag to check if any process can execute

        for (int i = 0; i < p; i++) {
            if (!done[i]) { // Process not yet completed
                int canRun = 1;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > available[j]) {
                        canRun = 0; // Process cannot run
                        break;
                    }
                }
                if (canRun) { // Process can run
                    safe[count++] = i;
                    done[i] = 1;
                    found = 1;

                    // Update available resources
                    for (int j = 0; j < r; j++)
                        available[j] += allocation[i][j];
                }
            }
        }

        // If no process can execute, no safe sequence exists
        if (!found) {
            printf("\nNo safe sequence exists.\n");
            return 1;
        }
    }

    // Print the safe sequence
    printf("\nSafe sequence is: ");
    for (int i = 0; i < p; i++)
        printf("P%d ", safe[i]);
    printf("\n");

    return 0;
}
