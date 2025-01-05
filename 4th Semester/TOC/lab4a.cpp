#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void check(char *str)
{
    int flag=0;
    int n = strlen(str);
    if(isalpha(str[0])||str[0]=='_')
    flag=1;
  //  else
  //  printf("Not a valid identifier.");
    for(int i=1;i<n;i++)
    {
        if(!(isalpha(str[i]))||(str[i]>='0'&& str[i]<='9')||str[i]=='_')
        flag=0;
    }
    if(flag==1)
     printf("It's a valid identifier.\n");
    else
    printf("It's not a valid identifier.\n");

}

int isKeyword(char *str)
{
    int flag=0;
    char keywords[][50] = {"auto", "break", "case", "char", "const", "continue", "default",
                           "do", "double", "else", "enum", "extern", "float", "for", "goto",
                           "if", "int", "long", "register", "return", "short", "signed",
                           "sizeof", "static", "struct", "switch", "typedef", "union",
                           "unsigned", "void", "volatile", "while"};

    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
    {
        if (strcmp(str, keywords[i]) == 0)
        {
            flag= 1;
        }
    }
    if(flag==1)
    printf("It's a keyword.\n");
else
{
    printf("It's not a keyword.\n");
    check(str);

}

    return 0;
}


int main() {
   char str[100];
   int i,n;
   here: printf("\nEnter the string to be checked: ");
   scanf("%s", str);
   isKeyword(str);
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

