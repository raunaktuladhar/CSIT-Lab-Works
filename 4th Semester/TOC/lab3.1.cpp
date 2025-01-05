#include <stdio.h>
#include <stdlib.h>
void state(char *str)
{ 
    char f = '1',g='1';
  for (int i = 0; str[i] != '\0'; i++) {
      switch (f) {
         case '1':
           if (str[i] == '1')
             f = '2';
            break;
         case '2':
            if (str[i] == '1'||str[i] == '0' ) 
            f = '3';
            break;
          case '3':
            if (str[i] == '0' )  
            f = '1';
         else if(str[i]=='1')
         {
         f='2' ;
         g='3';
         }
            break;
      
      }
  }
   
   if (f == '3'|| g == '3')

      printf("String is accepted\n");
   else
      printf("String is not accepted\n");

}


int main() 
{
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
