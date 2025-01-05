// LRU

#include <stdio.h>

#define MAX_LENGTH 100

void getReferenceString(int rs[], int length) {
    printf("Enter the reference string: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &rs[i]);
    }
}

int isPageHit(int m[], int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (m[i] == page) {
            return i; // Page hit, return index of hit page
        }
    }
    return -1; // Page fault
}

int getLRUPageIndex(int count[], int frameCount) {
    int minIndex = 0;
    for (int i = 1; i < frameCount; i++) {
        if (count[i] < count[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void printMemoryLayout(int m[], int frameCount, char* status) {
    printf("%s:\t ", status);
    for (int i = 0; i < frameCount; i++) {
        if (m[i] == -1) {
            printf(" \t");
        } else {
            printf("%d\t", m[i]);
        }
    }
    printf("\n");
}

int main() {
    printf("Least Recently Used\n");
    printf("Enter the length of the reference string: ");
    int length;
    scanf("%d", &length);

    if (length <= 0 || length > MAX_LENGTH) {
        printf("Invalid length of the reference string.\n");
        return 1;
    }

    int rs[MAX_LENGTH];
    getReferenceString(rs, length);

    printf("Enter the number of frames: ");
    int frameCount;
    scanf("%d", &frameCount);

    if (frameCount <= 0) {
        printf("Invalid number of frames.\n");
        return 1;
    }

    int m[frameCount], count[frameCount];
    for (int i = 0; i < frameCount; i++) {
        count[i] = 0;
        m[i] = -1;
    }

    int pageFault = 0, pageHit = 0, next = 0;

    for (int i = 0; i < length; i++) {
        int hitIndex = isPageHit(m, frameCount, rs[i]);
        if (hitIndex == -1) {
            if (next < frameCount) {
                m[next] = rs[i];
                count[next] = next;
                next++;
                printMemoryLayout(m, frameCount, "Miss");
            } else {
                int pageIndex = getLRUPageIndex(count, frameCount);
                m[pageIndex] = rs[i];
                count[pageIndex] = next;
                next++;
                printMemoryLayout(m, frameCount, "Miss");
            }
            pageFault++;
        } else {
            count[hitIndex] = next;
            next++;
            printMemoryLayout(m, frameCount, "Hit");
            pageHit++;
        }
    }

    printf("Number of page hits: %d\n", pageHit);
    printf("Number of page faults: %d\n", pageFault);

    return 0;
}


