#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], i, j, totalWT = 0, totalTAT = 0, temp;
    float avgWT, avgTAT;

    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get burst times
    printf("\nEnter Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort burst times in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) { // Swap if needed
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // Calculate waiting time
    wt[0] = 0; // First process has no waiting time
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        totalWT += wt[i]; // Add to total waiting time
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        totalTAT += tat[i]; // Add to total turnaround time
    }

    // Print results
    printf("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t %d\t\t %d\t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    // Calculate and display averages
    avgWT = (float)totalWT / n;
    avgTAT = (float)totalTAT / n;
    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}
