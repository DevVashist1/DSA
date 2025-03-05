#include <stdio.h>

// Structure to store process information
struct Process {
    int pid, arrival_time, burst_time, completion_time, turnaround_time, waiting_time;
    int completed;
};

int main() {
    int n, completed = 0, current_time = 0, min_index;
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
        p[i].completed = 0; // Mark process as not completed
    }

    int total_wt = 0, total_tat = 0;

    while (completed < n) {
        min_index = -1;
        int min_bt = 9999;

        // Find the process with the shortest burst time among arrived processes
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && !p[i].completed && p[i].burst_time < min_bt) {
                min_bt = p[i].burst_time;
                min_index = i;
            }
        }

        if (min_index == -1) {
            // If no process is available, increment time
            current_time++;
        } else {
            // Execute the shortest job
            p[min_index].completion_time = current_time + p[min_index].burst_time;
            p[min_index].turnaround_time = p[min_index].completion_time - p[min_index].arrival_time;
            p[min_index].waiting_time = p[min_index].turnaround_time - p[min_index].burst_time;
            current_time = p[min_index].completion_time;

            total_wt += p[min_index].waiting_time;
            total_tat += p[min_index].turnaround_time;

            p[min_index].completed = 1;
            completed++;
        }
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
