// C Program to simulate FCFS Disk Scheduling Algorithm

#include <stdio.h>
#include <math.h>

int size = 8;

void FCFS(int arr[], int head, int size)
{
    int seek_count = 0;
    int cur_track, distance;

    for (int i = 0; i < size; i++)
    {
        cur_track = arr[i];

        // calculate absolute distance
        distance = fabs(head - cur_track);

        // increase the total count
        seek_count += distance;

        // accessed track is now new head
        head = cur_track;
    }

    printf("Total number of seek operations: %d\n", seek_count);

    // Seek sequence would be the same
    // as request array sequence
    printf("Seek Sequence is: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}

// Driver code
int main()
{
    // request array
    int arr[8];
    int head, size;
	printf("FCFS Disk Scheduling Algorithm\n");
    printf("Enter the size of the request queue (max 8): ");
    scanf("%d", &size);

    if (size > 8)
    {
        printf("Size cannot exceed 8. Setting size to 8.\n");
        size = 8;
    }

    printf("Enter the request queue: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the starting position: ");
    scanf("%d", &head);

    FCFS(arr, head, size);

    return 0;
}

 
