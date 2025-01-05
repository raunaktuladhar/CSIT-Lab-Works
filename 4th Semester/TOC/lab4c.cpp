#include <stdio.h>
#include <stdlib.h>
void state(char *str)
{ 
    char f = 'a';
    for ( int i = 0; str[i] != '\0'; i++) 
   {
      switch (f) 
      {
         case 'a':
            if (str[i] == '/') 
            f = 'b';
            else if (str[i] == '*')
             f = 'd';
            break;
         case 'b':
            if (str[i] == '/') 
            f = 'c';
            else if (str[i] == '*')
            f = 'e';
            break;
         case 'e':
            if (str[i] == '/') 
            f = 'e';
            else if (str[i] == '*') 
            f = 'f';
            break;
        case 'd':
         if (str[i] == '/'||str[i] == '*')
             f = 'd';
            break;
         case 'f':
         if(str[i]=='/')
         f='c';
      else
      f='f';
         break;


        
      }
   }
   
   if (f == 'c')
      printf("comment is accepted\n");
   else
      printf("comment is not accepted\n");


}

int main() {
   char str[100];
   int i,n;
   here: printf("\nEnter the comment format to be checked: ");
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
