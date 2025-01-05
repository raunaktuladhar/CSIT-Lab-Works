#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int work[MAX_RESOURCES];
int finish[MAX_PROCESSES];

int num_processes, num_resources;

void initialize() {
	printf("Banker's Algorithm\n");
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter available resources:\n");
    for (int i = 0; i < num_resources; i++)
        scanf("%d", &available[i]);

    printf("Enter maximum resources for each process:\n");
    for (int i = 0; i < num_processes; i++)
        for (int j = 0; j < num_resources; j++)
            scanf("%d", &maximum[i][j]);

    printf("Enter allocation for each process:\n");
    for (int i = 0; i < num_processes; i++)
        for (int j = 0; j < num_resources; j++)
            scanf("%d", &allocation[i][j]);
}

void calculate_need() {
    for (int i = 0; i < num_processes; i++)
        for (int j = 0; j < num_resources; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
}

int safety_algorithm() {
    for (int i = 0; i < num_resources; i++)
        work[i] = available[i];

    for (int i = 0; i < num_processes; i++)
        finish[i] = 0;

    int sequence[MAX_PROCESSES];
    int seq_index = 0;

    for (int i = 0; i < num_processes; i++) {
        if (finish[i] == 0) {
            int can_allocate = 1;
            for (int j = 0; j < num_resources; j++) {
                if (need[i][j] > work[j]) {
                    can_allocate = 0;
                    break;
                }
            }
            if (can_allocate) {
                for (int j = 0; j < num_resources; j++)
                    work[j] += allocation[i][j];
                finish[i] = 1;
                sequence[seq_index++] = i;
                i = -1;
            }
        }
    }

    for (int i = 0; i < num_processes; i++) {
        if (finish[i] == 0)
            return 0;
    }

    printf("Safe sequence is: ");
    for (int i = 0; i < num_processes; i++)
        printf("%d ", sequence[i]);
    printf("\n");

    return 1;
}

int request_resources(int pid, int request[]) {
    for (int i = 0; i < num_resources; i++) {
        if (request[i] > need[pid][i] || request[i] > available[i])
            return 0;
    }

    for (int i = 0; i < num_resources; i++) {
        available[i] -= request[i];
        allocation[pid][i] += request[i];
        need[pid][i] -= request[i];
    }

    if (!safety_algorithm()) {
        for (int i = 0; i < num_resources; i++) {
            available[i] += request[i];
            allocation[pid][i] -= request[i];
            need[pid][i] += request[i];
        }
        return 0;
    }

    return 1;
}

int main() {
    initialize();
    calculate_need();
	
    printf("\nEnter the process id for resource request: ");
    int pid;
    scanf("%d", &pid);

    printf("Enter the resource request for process %d:\n", pid);
    int request[MAX_RESOURCES];
    for (int i = 0; i < num_resources; i++)
        scanf("%d", &request[i]);

    if (request_resources(pid, request))
        printf("Resource request granted.\n");
    else
        printf("Resource request denied.\n");

    return 0;
}


