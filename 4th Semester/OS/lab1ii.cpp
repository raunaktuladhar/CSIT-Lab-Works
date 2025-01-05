// SJF

#include<stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int service_time[n];
    service_time[0] = 0;
    wt[0] = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n ; i++) {
        // Add burst time of previous processes
        service_time[i] = service_time[i-1] + bt[i-1];

        // Find waiting time for current process
        wt[i] = service_time[i] - processes[i];
        
        // If waiting time is negative, make it 0
        if (wt[i] < 0)
            wt[i] = 0;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time by adding burst time and waiting time
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void findAvgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    // Find waiting time of all processes
    findWaitingTime(processes, n, bt, wt);

    // Find turnaround time of all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }

    // Calculate average waiting time and average turnaround time
    float avg_wt = total_wt / n;
    float avg_tat = total_tat / n;

    // Display results
    printf("Processes  Burst Time  Waiting Time  Turn-Around Time\n");
    for (int i = 0; i < n; i++)
        printf("   %d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int n;
     printf("SJF\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival Time for Process %d: ", i+1);
        scanf("%d", &processes[i]);
        printf("Burst Time for Process %d: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    findAvgTime(processes, n, burst_time);

    return 0;
}

