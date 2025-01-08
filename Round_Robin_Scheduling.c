#include <stdio.h>

int main() {
    int n;
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n];
    int total_wt = 0, total_tat = 0, current_time = 0;
    int time_quantum;

    // Input process details (arrival time and burst time)
    for (int i = 0; i < n; i++) {
        printf("Enter Details of Process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Initialize remaining time with burst time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    int processes_left = n;

    // Round Robin Scheduling
    printf("\nProcess ID\tBurst Time\tTurnaround Time\tWaiting Time\n");

    while (processes_left > 0) {
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                int time_used = (rt[i] > time_quantum) ? time_quantum : rt[i];
                current_time += time_used;
                rt[i] -= time_used;

                // If the process is completed
                if (rt[i] == 0) {
                    int tat = current_time - at[i];
                    int wt = tat - bt[i];

                    printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], tat, wt);

                    total_wt += wt;
                    total_tat += tat;

                    processes_left--;
                }
            }
        }
    }

    // Calculate and print the average waiting and turnaround times
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);

    return 0;
}
