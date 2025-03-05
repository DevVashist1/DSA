#include <stdio.h>

struct Process {
    int id, arrival, burst, priority, completion, turnaround, waiting;
};

void sortProcesses(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority || 
               (p[i].priority == p[j].priority && p[i].arrival > p[j].arrival)) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void priorityScheduling(struct Process p[], int n) {
    sortProcesses(p, n);
    
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival)
            time = p[i].arrival;
        time += p[i].burst;
        p[i].completion = time;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
    }
    
    printf("\nPID  Arrival  Burst  Priority  Completion  Turnaround  Waiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d    %d       %d       %d        %d         %d          %d\n", 
               p[i].id, p[i].arrival, p[i].burst, p[i].priority, 
               p[i].completion, p[i].turnaround, p[i].waiting);
    }
}

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process p[n];
    
    for (int i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &p[i].arrival);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &p[i].burst);
        printf("Process %d Priority (lower value = higher priority): ", i + 1);
        scanf("%d", &p[i].priority);
        p[i].id = i + 1;
    }
    
    priorityScheduling(p, n);
    
    return 0;
}
