#include <stdio.h>
#define MAX 100

// Structure to store process details
struct Process {
    int id;       // Process ID
    int at;       // Arrival Time
    int bt;       // Burst Time
    int rt;       // Remaining Time
};

int main() {
    int num, time = 0, done = 0;
    struct Process p[MAX];
    int total_wt = 0, total_tat = 0;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &num);

    // Input arrival and burst times for each process
    for (int i = 0; i < num; i++) {
        printf("Enter arrival and burst times for process %d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].id = i + 1;
        p[i].rt = p[i].bt;
    }

    // Scheduling loop
    while (done < num) {
        int shortest = -1;

        // Find process with shortest remaining time
        for (int i = 0; i < num; i++) {
            if (p[i].rt > 0 && p[i].at <= time) {
                if (shortest == -1 || p[i].rt < p[shortest].rt) {
                    shortest = i;
                }
            }
        }

        // If no process is ready, increment time
        if (shortest == -1) {
            time++;
            continue;
        }

        // Process the selected job
        p[shortest].rt--;
        time++;

        // If the process finishes
        if (p[shortest].rt == 0) {
            done++;
            int tat = time - p[shortest].at; // Turnaround Time
            int wt = tat - p[shortest].bt;   // Waiting Time

            total_tat += tat;
            total_wt += wt;

            printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", 
                   p[shortest].id, wt, tat);
        }
    }

    // Calculate and display averages
    printf("\nAverage Waiting Time = %.2f\n", (float)total_wt / num);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / num);

    return 0;
}
