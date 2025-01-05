#include <stdio.h>
#include <stdlib.h>
void state(char *str)
{ 
char  f = '1';
   for (int i = 0; str[i] != '\0'; i++) {
      switch (f) {
         case '1':
            if (str[i] == 'p')          
            f = '2';
            break;
         case '2':
             if (str[i] == 'r') 
             f = '3';
            break;
         case '3':
            if (str[i] == 'a') 
            f = '4';
            break;
        case '4':
            if (str[i] == 'b') 
            f = '5';
            break;
         case '5':
            if (str[i] == 'i') 
            f = '6';
            break;
            
            case '6':
            	if(str[i] == 'n')
            	f = '7';
            	break;
      }
   }
   
   if (f == '7')

      printf("Name is accepted\n");
   else
      printf("Name is not accepted\n");


}

int main() {
   char str[100];
   int i,n;
   here: printf("\nEnter name to be checked: ");
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
