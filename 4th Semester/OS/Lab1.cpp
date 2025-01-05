// 1. FCFS

#include <stdio.h>

void fcfs(int processes[], int n, int at[], int bt[]) {
    int ct[n], wt[n], tat[n];

    // Initialize completion time of first process
    ct[0] = bt[0];

    // Calculate completion time for each process
    for (int i = 1; i < n; i++)
        ct[i] = ct[i - 1] + bt[i];

    // Calculate turnaround time and waiting time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Display results
    printf("Process \t Arrival Time \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \n", processes[i], at[i], bt[i], wt[i], tat[i]);

    // Calculate and display average waiting time and average turnaround time
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int n;
    printf("FCFS\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], at[n], bt[n];

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        processes[i] = i + 1;
    }

    fcfs(processes, n, at, bt);

    return 0;
}


