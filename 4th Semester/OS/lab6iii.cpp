// Hierarchial Lvl Directory Structure

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct Directory {
    char name[MAX_NAME_LENGTH];
    struct Directory* subdirectories;
    struct File* files;
} Directory;

typedef struct File {
    char name[MAX_NAME_LENGTH];
    struct File* next;
} File;

Directory* masterDirectory = NULL;

Directory* createDirectory(const char* name) {
    Directory* newDir = (Directory*)malloc(sizeof(Directory));
    strcpy(newDir->name, name);
    newDir->subdirectories = NULL;
    newDir->files = NULL;
    return newDir;
}

File* createFile(const char* name) {
    File* newFile = (File*)malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->next = NULL;
    return newFile;
}

void freeFiles(File* file) {
    while (file != NULL) {
        File* nextFile = file->next;
        free(file);
        file = nextFile;
    }
}

void freeDirectories(Directory* directory) {
    if (directory != NULL) {
        freeFiles(directory->files);

        Directory* subdir = directory->subdirectories;
        while (subdir != NULL) {
            Directory* nextSubdir = subdir->subdirectories;
            freeDirectories(subdir);
            subdir = nextSubdir;
        }

        free(directory);
    }
}

Directory* findChildDirectory(Directory* parent, const char* name) {
    Directory* current = parent->subdirectories;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->subdirectories;
    }
    return NULL;
}

File* findFile(Directory* parent, const char* name) {
    File* current = parent->files;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void createChildDirectory() {
    if (masterDirectory == NULL) {
        printf("Create the master directory first!\n");
        return;
    }

    char childName[MAX_NAME_LENGTH];
    printf("Enter the name of the child directory: ");
    scanf("%s", childName);

    if (findChildDirectory(masterDirectory, childName) != NULL) {
        printf("Child directory '%s' already exists in the master directory.\n", childName);
        return;
    }

    Directory* newChild = createDirectory(childName);

    if (masterDirectory->subdirectories == NULL) {
        masterDirectory->subdirectories = newChild;
    } else {
        Directory* current = masterDirectory->subdirectories;
        while (current->subdirectories != NULL) {
            current = current->subdirectories;
        }
        current->subdirectories = newChild;
    }

    printf("Child directory '%s' created successfully.\n", childName);
}

void createSubdirectoryOrFile(Directory* parent) {
    char name[MAX_NAME_LENGTH];
    int choice;
    printf("Enter the name: ");
    scanf("%s", name);

    printf("Choose an option:\n");
    printf("1. Create Subdirectory\n");
    printf("2. Create File\n");
    scanf("%d", &choice);

    if (findChildDirectory(parent, name) != NULL || findFile(parent, name) != NULL) {
        printf("A subdirectory or file with name '%s' already exists.\n", name);
        return;
    }

    if (choice == 1) {
        Directory* newSubdir = createDirectory(name);

        if (parent->subdirectories == NULL) {
            parent->subdirectories = newSubdir;
        } else {
            Directory* current = parent->subdirectories;
            while (current->subdirectories != NULL) {
                current = current->subdirectories;
            }
            current->subdirectories = newSubdir;
        }

        printf("Subdirectory '%s' created successfully.\n", name);
    } else if (choice == 2) {
        File* newFile = createFile(name);

        if (parent->files == NULL) {
            parent->files = newFile;
        } else {
            File* current = parent->files;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newFile;
        }

        printf("File '%s' created successfully.\n", name);
    }
}

void listDirectoriesFiles(Directory* parent) {
    printf("Subdirectories:\n");
    Directory* subdir = parent->subdirectories;
    while (subdir != NULL) {
        printf("- %s\n", subdir->name);
        subdir = subdir->subdirectories;
    }

    printf("\nFiles:\n");
    File* file = parent->files;
    while (file != NULL) {
        printf("- %s\n", file->name);
        file = file->next;
    }
}

int main() {
    int option;
    printf("Hierarchial Directory Structure\n");
	printf("\nChoose an option:\n");
    printf("1. Create Master Directory\n");
    printf("2. Create Child Directory\n");
    printf("3. Create Subdirectory or File\n");
    printf("4. List Directories and Files\n");
    printf("0. Exit\n");
    do {
    	printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (masterDirectory == NULL) {
                    char masterName[MAX_NAME_LENGTH];
                    printf("Enter the name of the master directory: ");
                    scanf("%s", masterName);
                    masterDirectory = createDirectory(masterName);
                    printf("Master directory '%s' created successfully.\n", masterName);
                } else {
                    printf("Master directory already exists!\n");
                }
                break;
            case 2:
                createChildDirectory();
                break;
            case 3:
                if (masterDirectory != NULL) {
                    createSubdirectoryOrFile(masterDirectory);
                } else {
                    printf("Create the master directory first!\n");
                }
                break;
            case 4:
                if (masterDirectory != NULL) {
                    listDirectoriesFiles(masterDirectory);
                } else {
                    printf("Create the master directory first!\n");
                }
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 0);

    freeDirectories(masterDirectory); // Free allocated memory

    return 0;
}


