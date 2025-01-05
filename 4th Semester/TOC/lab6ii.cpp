// 6.2 Convert RE to FA - a(a+b)*b
// not accepted abab
// accepted baa

#include <stdio.h>
#include <stdlib.h>

void state(char *str) { 
    char f = 'a';
    int i = 0;

    // Check if the first character is 'a'
    if (str[i] != 'a') {
        f = 'x'; // Mark as rejected state
    }
    i++;

    while (str[i] != '\0' && f != 'x') {
        switch (f) {
            case 'a':
                if (str[i] == 'a') {
                    f = 'a'; // Stay in the same state
                } else if (str[i] == 'b') {
                    f = 'b'; // Move to next state
                } else {
                    f = 'x'; // Mark as rejected state
                }
                break;
            case 'b':
                if (str[i] == 'a' || str[i] == 'b') {
                    f = 'b'; // Stay in the same state
                } else {
                    f = 'x'; // Mark as rejected state
                }
                break;
        }
        i++;
    }
   
    // Check if the last character is 'b' and the state is valid
    if (f == 'b' && str[i - 1] == 'b' && str[i] == '\0') {
        printf("String is accepted\n");
    } else {
        printf("String is not accepted\n");
    }
}

int main() {
    char str[100];
    int n;
    printf("Convert RE to FA - a(a+b)*b\n");
    do {
        printf("\nEnter the string to be checked: ");
        scanf("%s", str);
        state(str);

        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &n);
    } while (n != 0);

    return 0;
}


