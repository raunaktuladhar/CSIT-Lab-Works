#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRS 10
#define MAX_FILES 10
#define MAX_NAME_LENGTH 50

struct Directory {
    char name[MAX_NAME_LENGTH];
    int num_files;
    char files[MAX_FILES][MAX_NAME_LENGTH];
};

struct MasterDirectory {
    char name[MAX_NAME_LENGTH];
    int num_dirs;
    struct Directory directories[MAX_DIRS];
};

int masterDirectoryExists = 0;

void createMasterDirectory(struct MasterDirectory *master) {
    if (masterDirectoryExists) {
        puts("Master directory already exists.");
        return;
    }

    puts("Enter name for master directory:");
    scanf("%s", master->name);
    masterDirectoryExists = 1;
    master->num_dirs = 0;
    puts("Master directory created successfully.");
}

void createDirectory(struct MasterDirectory *master, int isMaster) {
    if (isMaster && masterDirectoryExists) {
        puts("Master directory already exists.");
        return;
    }

    char name[MAX_NAME_LENGTH];
    puts("Enter name for directory:");
    scanf("%s", name);

    for (int i = 0; i < master->num_dirs; i++) {
        if (strcmp(master->directories[i].name, name) == 0) {
            puts("Directory with the same name already exists.");
            return;
        }
    }

    strcpy(master->directories[master->num_dirs++].name, name);
    printf("Directory created successfully.\n");
}

void createFile(struct MasterDirectory *master) {
    char dir_name[MAX_NAME_LENGTH], file_name[MAX_NAME_LENGTH];
    puts("Enter name of the directory to add file:");
    scanf("%s", dir_name);

    for (int i = 0; i < master->num_dirs; i++) {
        if (strcmp(master->directories[i].name, dir_name) == 0) {
            if (master->directories[i].num_files >= MAX_FILES) {
                puts("Cannot create more files in this directory.");
                return;
            }

            puts("Enter name for file:");
            scanf("%s", file_name);

            for (int j = 0; j < master->directories[i].num_files; j++) {
                if (strcmp(master->directories[i].files[j], file_name) == 0) {
                    puts("File already exists in this directory.");
                    return;
                }
            }

            strcpy(master->directories[i].files[master->directories[i].num_files++], file_name);
            puts("File created successfully.");
            return;
        }
    }

    puts("Directory not found.");
}

void listDirectories(struct MasterDirectory *master) {
    puts("List of directories:");
    for (int i = 0; i < master->num_dirs; i++) {
        printf("%d. %s\n", i + 1, master->directories[i].name);
    }
}

void listFiles(struct MasterDirectory *master) {
    char dir_name[MAX_NAME_LENGTH];
    puts("Enter name of the directory to list files:");
    scanf("%s", dir_name);

    for (int i = 0; i < master->num_dirs; i++) {
        if (strcmp(master->directories[i].name, dir_name) == 0) {
            puts("List of files:");
            for (int j = 0; j < master->directories[i].num_files; j++) {
                printf("%d. %s\n", j + 1, master->directories[i].files[j]);
            }
            return;
        }
    }

    puts("Directory not found.");
}

int main() {
    struct MasterDirectory master = { "", 0, { { "", 0, { "" } } } };
    int choice;
    puts("Two-Level Directory Structure\n");
	 puts("\n1. Create master directory");
        puts("2. Create child directory");
        puts("3. Create file");
        puts("4. List directories");
        puts("5. List files in a directory");
        puts("0. Exit");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createMasterDirectory(&master);
                break;
            case 2:
                createDirectory(&master, 0);
                break;
            case 3:
                createFile(&master);
                break;
            case 4:
                listDirectories(&master);
                break;
            case 5:
                listFiles(&master);
                break;
            case 0:
                puts("Exiting program.");
                break;
            default:
                puts("Invalid choice. Please try again.");
        }
    } while (choice != 0);

    return 0;
}


