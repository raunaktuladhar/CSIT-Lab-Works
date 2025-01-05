// Construct PDA for a^n b^n c^m; n,m>=1

// accept abc
// reject bac

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isLanguageMatch(char *str) {
    int countA = 0, countB = 0, countC = 0;
    
    // Count the number of 'a's, 'b's, and 'c's in the string
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a')
            countA++;
        else if (str[i] == 'b')
            countB++;
        else if (str[i] == 'c')
            countC++;
        else
            return false; // If any other character is encountered, return false
    }
    
    // Check if the string matches the language definition
    if (countA == countB && countC > 0 && countA > 0)
        return true;
    else
        return false;
}

int main() {
    char str[100];
    char choice;
    printf("PDA for a^n b^n c^m; n,m>=1\n");
    do {
        printf("Enter a string: ");
        scanf("%s", str);
        
        if (isLanguageMatch(str))
            printf("The string matches the language.\n");
        else
            printf("The string does not match the language.\n");
        
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &choice); 
        
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}

