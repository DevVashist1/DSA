#include <stdio.h>

// Structure to store process information
struct Process {
    int pid, arrival_time, burst_time, completion_time, turnaround_time, waiting_time;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input process details
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d - Arrival Time: ", p[i].pid);
        scanf("%d", &p[i].arrival_time);
        printf("Process %d - Burst Time: ", p[i].pid);
        scanf("%d", &p[i].burst_time);
    }

    // Sort processes by Arrival Time (FCFS scheduling)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Compute Completion, Turnaround, and Waiting Times
    int total_wt = 0, total_tat = 0;
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
        }
        p[i].completion_time = current_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        current_time = p[i].completion_time;

        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    // Print results
    printf("\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }

    // Calculate and print averages
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);

    return 0;
}
