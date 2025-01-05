#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 20
#define MAX_DIR_NAME_LENGTH 20

struct Directory {
    char name[MAX_DIR_NAME_LENGTH];
    char files[MAX_FILES][MAX_FILENAME_LENGTH];
    int fileCount;
};

void initDirectory(struct Directory *dir, char *name) {
    strcpy(dir->name, name);
    dir->fileCount = 0;
}

void createFile(struct Directory *dir, char *filename) {
    if (dir->fileCount < MAX_FILES) {
        strcpy(dir->files[dir->fileCount], filename);
        dir->fileCount++;
        printf("File '%s' created successfully in directory '%s'.\n", filename, dir->name);
    } else {
        printf("Directory is full. Cannot create more files.\n");
    }
}

void deleteFile(struct Directory *dir, char *filename) {
    int i, found = 0;
    for (i = 0; i < dir->fileCount; i++) {
        if (strcmp(dir->files[i], filename) == 0) {
            found = 1;
            printf("File '%s' deleted successfully from directory '%s'.\n", filename, dir->name);
            // Shift files to fill the gap
            for (int j = i; j < dir->fileCount - 1; j++) {
                strcpy(dir->files[j], dir->files[j + 1]);
            }
            dir->fileCount--;
            break;
        }
    }
    if (!found) {
        printf("File '%s' not found in directory '%s'.\n", filename, dir->name);
    }
}

void listFiles(struct Directory *dir) {
    printf("Files in directory '%s':\n", dir->name);
    for (int i = 0; i < dir->fileCount; i++) {
        printf("%s\n", dir->files[i]);
    }
}

int main() {
    struct Directory dir;
    char dirname[MAX_DIR_NAME_LENGTH];
    char filename[MAX_FILENAME_LENGTH];
    printf("Single-Level Directory\n");
    printf("Enter directory name: ");
    scanf("%s", dirname);

    initDirectory(&dir, dirname);

    int choice;
    
    printf("\n1. Create File\n2. Delete File\n3. List Files\n4. Exit\n");
    while (1) {
         printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename to create: ");
                scanf("%s", filename);
                createFile(&dir, filename);
                break;
            case 2:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                deleteFile(&dir, filename);
                break;
            case 3:
                listFiles(&dir);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}


