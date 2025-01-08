#include <stdio.h>

int main() {
    int pid[15]; // Array to store process IDs
    int bt[15];  // Array to store burst times
    int n;       // Number of processes

    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get process IDs
    printf("Enter process IDs for all processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pid[i]);
    }

    // Get burst times
    printf("Enter burst times for all processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    int wt[n];   // Array to store waiting times
    wt[0] = 0;   // Waiting time for the first process is 0

    // Calculate waiting times for each process
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    // Print process table header
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    float twt = 0.0; // Total waiting time
    float tat = 0.0; // Total turnaround time

    // Calculate and print details for each process
    for (int i = 0; i < n; i++) {
        int tat_i = bt[i] + wt[i]; // Turnaround time for the current process
        printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat_i);

        // Accumulate total waiting and turnaround times
        twt += wt[i];
        tat += tat_i;
    }

    // Calculate and print averages
    float awt = twt / n; // Average waiting time
    float att = tat / n; // Average turnaround time
    printf("Average Waiting Time = %.2f\n", awt);
    printf("Average Turnaround Time = %.2f\n", att);

    return 0;
}
