#include <stdio.h>

int main() {
    int n, bt[20], pri[20], wt[20], tat[20], p[20], i, j, total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority for each process
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time and Priority for process %d: ", i + 1);
        scanf("%d %d", &bt[i], &pri[i]);
        p[i] = i + 1; // Process ID
    }

    // Sort processes by priority
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pri[j] < pri[i]) { // Higher priority first
                // Swap priority, burst time, and process ID
                int temp = pri[i]; pri[i] = pri[j]; pri[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    // Calculate waiting time
    wt[0] = 0; // First process has no waiting time
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        total_wt += wt[i];
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_tat += tat[i];
    }

    // Display process details
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pri[i], wt[i], tat[i]);
    }

    // Calculate and display averages
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
