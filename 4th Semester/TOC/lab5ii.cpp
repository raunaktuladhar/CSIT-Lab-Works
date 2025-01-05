#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void state(char *str)
{ 
    char f = 'a';
    for ( int i = 0; str[i] != '\0'; i++) 
   {
      switch (f) 
      {
         case 'a'://start
            if (isalpha(str[i])||str[i] >= '0'&& str[i]<='9' ) 
            f = 'b';
           
            break;
         case 'b'://username
            if (isalpha(str[i])||str[i] >= '0'&& str[i]<='9'||str[i] == '_' ||str[i] == '.'|| str[i] == '-') 
            f = 'b';
            else if (str[i] == '@') 
            f = 'c';
       
            break;
         case 'c'://at
         if (isalpha(str[i])||str[i] >= '0'&& str[i]<='9' ) 
            f = 'e';
         break;
      
         case 'e': //domain
          if (isalpha(str[i])||str[i] >= '0'&& str[i]<='9'||str[i] == '_' || str[i] == '-') 
            f = 'e';
         else if (str[i] == '.')
          f='g';
       
       break;
      case 'g'://DOT
      if (isalpha(str[i]))
      f='h';
   break;
     
    case 'h'://TOP level domain
      if (isalpha(str[i]))
      f='h';
     break;

      

    }
   }
   
   if (f == 'h')
      printf("Email address is valid\n");
   else
      printf("Email address is not valid\n");


}

int main() {
   char str[100];
   int i,n;
   here: printf("\nEnter an email address to be checked: ");
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
