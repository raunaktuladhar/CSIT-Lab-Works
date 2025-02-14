#include <stdio.h>
#include <string.h>

int main() {
    char com[30];
    char choice;
    int i, a = 0;

    do {
        printf("Enter comment: ");
        fgets(com, sizeof(com), stdin);  // Use fgets to allow spaces in the input

        // Check for single-line comment
        if (com[0] == '/' && com[1] == '/') {
            printf("\nIt is a comment (single-line)");
        } 
        // Check for multi-line comment
        else if (com[0] == '/' && com[1] == '*') {
            for (i = 2; i < strlen(com) - 1; i++) {
                if (com[i] == '*' && com[i + 1] == '/') {
                    printf("\nIt is a comment (multi-line)");
                    a = 1;
                    break;
                }
            }
            if (a == 0) {
                printf("\nIt is not a comment (multi-line)");
            }
        } 
        // If the input doesn't match any of the above
        else {
            printf("\nIt is not a comment");
        }

        // Ask if the user wants to continue
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);  // The space before %c skips any leftover newline character
        getchar();  // To consume the newline left by scanf

    } while (choice == 'y' || choice == 'Y');
    return 0;
}

