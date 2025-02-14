#include <stdio.h>
#include <ctype.h>

int main() {
    char a[10];
    int flag, i;
    char choice;
    
    do {
        printf("Enter an identifier: ");
        scanf("%s", a);
        
        if (isalpha(a[0]) || a[0] == '_') {
            flag = 1;
        } else {
            flag = 0;
        }
        
        i = 1;
        while (a[i] != '\0') {
            if (!isdigit(a[i]) && !isalpha(a[i]) && a[i] != '_') {
                flag = 0;
                break;
            }
            i++;
        }
        
        if (flag == 1) {
            printf("\nValid identifier\n");
        } else {
            printf("\nNot a valid identifier\n");
        }
        
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}
