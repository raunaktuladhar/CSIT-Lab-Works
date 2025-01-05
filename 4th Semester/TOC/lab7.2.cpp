// Construct PDA for language wcw^r\w belongs to (0+1)^+
// accept 10101
// reject 11001

#include <stdio.h>
#include <string.h>

// Function to check if a string matches the pattern wcw^R
int isMatch(char *str) {
    int len = strlen(str);
    int mid = len / 2;
    int i;

    // Check if length is odd and first half equals the reverse of second half
    for (i = 0; i < mid; i++) {
        if (str[i] != str[len - 1 - i])
            return 0; // Not a match
    }

    return 1; // Match
}

int main() {
    char str[100];
    char choice;
	printf("PDA for wcw^r\w belongs to (0+1)^+\n");
    do {
        printf("Enter a string: ");
        scanf("%s", str);

        if (isMatch(str))
            printf("String matches the language.\n");
        else
            printf("String does not match the language.\n");

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice); 

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

