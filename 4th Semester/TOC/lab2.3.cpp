#include <stdio.h>
#include <stdlib.h>
void state(char *str)
{ 
    char f = 'a';
 for (int i = 0; str[i] != '\0'; i++) {
        switch (f) {
            case 'a':
                if (str[i] == '1') 
                f = 'a';
                else if (str[i] == '0') 
                f = 'b';
                break;

            case 'b':
                if (str[i] == '0') 
                f = 'c';
                else if (str[i] == '1')
                 f = 'a';
                break;
                
            case 'c':
                if (str[i] == '0') 
                f = 'c';
                else if (str[i] == '1')
                 f = 'd';
                break;

            case 'd':
                if (str[i] == '0' || str[i] == '1') 
                f = 'd';
                break;
        }
    }
   
   
   if (f == 'd')
      printf("String is accepted\n");
   else
      printf("String is not accepted\n");


}

int main() {
   char str[100];
   int i,n;
   here: printf("\nEnter the string to be checked: ");
   scanf("%s", str);
   state(str);
   do
   {
     printf("Enter 1:continue or 0:Exit ");
     scanf("%d",&n);
     switch(n)
     {
     case 1:
     goto here;
     break;
     case 0:
     exit(0);
     break;
     }

   }while(n!=0);

   return 0;
}
