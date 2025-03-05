#include <stdio.h>

struct Process {
    int id, arrival, burst, remaining, completion, turnaround, waiting;
};

void roundRobin(struct Process p[], int n, int quantum) {
    int time = 0, remaining = n;
    
    while (remaining > 0) {
        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0) {
                if (p[i].remaining > quantum) {
                    time += quantum;
                    p[i].remaining -= quantum;
                } else {
                    time += p[i].remaining;
                    p[i].completion = time;
                    p[i].turnaround = p[i].completion - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                    p[i].remaining = 0;
                    remaining--;
                }
            }
        }
    }
    
    printf("\nPID  Arrival  Burst  Completion  Turnaround  Waiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d    %d       %d       %d         %d          %d\n", 
               p[i].id, p[i].arrival, p[i].burst, p[i].completion, 
               p[i].turnaround, p[i].waiting);
    }
}

int main() {
    int n, quantum;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process p[n];
    
    for (int i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &p[i].arrival);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].id = i + 1;
        p[i].remaining = p[i].burst;
    }
    
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);
    
    roundRobin(p, n, quantum);
    
    return 0;
}
