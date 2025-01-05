// Optimal 

#include <stdio.h>

int search(int key, int frame_items[], int frame_occupied) {
    for (int i = 0; i < frame_occupied; i++)
        if (frame_items[i] == key)
            return 1;
    return 0;
}

void printCurrFrames(int item, int frame_items[], int frame_occupied, int max_frames, const char *hit_or_miss) {
    printf("\n%d \t\t", item);
    for (int i = 0; i < max_frames; i++) {
        if (i < frame_occupied)
            printf("%d \t\t", frame_items[i]);
        else
            printf(" \t\t");
    }
    printf("\t%s", hit_or_miss);
}

int predict(int ref_str[], int frame_items[], int refStrLen, int index, int frame_occupied) {
    int result = -1, farthest = index;
    for (int i = 0; i < frame_occupied; i++) {
        int j;
        for (j = index; j < refStrLen; j++) {
            if (frame_items[i] == ref_str[j]) {
                if (j > farthest) {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if (j == refStrLen)
            return i;
    }
    return (result == -1) ? 0 : result;
}

void optimalPage(int ref_str[], int refStrLen, int frame_items[], int max_frames) {
    int frame_occupied = 0;
    int hits = 0;
    for (int i = 0; i < refStrLen; i++) {
        if (search(ref_str[i], frame_items, frame_occupied)) {
            hits++;
            printCurrFrames(ref_str[i], frame_items, frame_occupied, max_frames, "hit");
            continue;
        }
        if (frame_occupied < max_frames) {
            frame_items[frame_occupied] = ref_str[i];
            frame_occupied++;
            printCurrFrames(ref_str[i], frame_items, frame_occupied, max_frames, "miss");
        } else {
            int pos = predict(ref_str, frame_items, refStrLen, i + 1, frame_occupied);
            frame_items[pos] = ref_str[i];
            printCurrFrames(ref_str[i], frame_items, frame_occupied, max_frames, "miss");
        }
    }
    printf("\nNumber of page hits: %d\n", hits);
    printf("Number of page faults: %d\n", refStrLen - hits);
}

int main() {
    int refStrLen, max_frames;
	printf("Optimal Page Replacement\n");
    printf("Enter the length of the reference string: ");
    scanf("%d", &refStrLen);

    int ref_str[refStrLen];
    printf("Enter the reference string elements: ");
    for (int i = 0; i < refStrLen; i++)
        scanf("%d", &ref_str[i]);

    printf("Enter the number of page frames: ");
    scanf("%d", &max_frames);

    int frame_items[max_frames];

    optimalPage(ref_str, refStrLen, frame_items, max_frames);
    return 0;
}


