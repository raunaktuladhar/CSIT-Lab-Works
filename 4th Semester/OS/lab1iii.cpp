// RR

#include <stdio.h>

#define MAX_PROCESS 10
#define TIME_QUANTUM 2

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

void roundRobinScheduling(struct Process processes[], int n) {
    int total_time = 0;
    int total_burst_time = 0;
    int remaining_processes = n;
    int total_turnaround_time = 0; // Added
    int total_waiting_time = 0;    // Added
    
    for (int i = 0; i < n; i++) {
        total_burst_time += processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\nRound Robin Scheduling (Time Quantum = 2)\n");
    printf("PID \t Arrival Time \t Burst Time \t Completion Time \t Turnaround Time \t Waiting Time\n");

    int current_time = 0;
    while (total_burst_time > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                int execute_time = (processes[i].remaining_time < TIME_QUANTUM) ? processes[i].remaining_time : TIME_QUANTUM;
                processes[i].remaining_time -= execute_time;
                current_time += execute_time;
                total_burst_time -= execute_time;

                if (processes[i].remaining_time == 0) {
                    remaining_processes--;
                    int completion_time = current_time;
                    int turnaround_time = completion_time - processes[i].arrival_time;
                    int waiting_time = turnaround_time - processes[i].burst_time;
                    printf("%d \t %d \t\t %d \t\t %d \t\t\t %d \t\t\t %d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, completion_time, turnaround_time, waiting_time);
                    
                    total_turnaround_time += turnaround_time; // Added
                    total_waiting_time += waiting_time;       // Added
                }
            }
        }

        if (remaining_processes == 0)
            break;
    }
    
    // Calculate average turnaround time and average waiting time
    double avg_turnaround_time = (double)total_turnaround_time / n;
    double avg_waiting_time = (double)total_waiting_time / n;
    
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
}

int main() {
    int n;
    struct Process processes[MAX_PROCESS];
	printf("Round Robin\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    roundRobinScheduling(processes, n);

    return 0;
}


