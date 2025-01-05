#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,k,n,a;
    char string[10],string1[10];
    printf("Enter string of {a,b}: ");
    scanf("%s",&string);
       n= strlen(string);
       do
       {
       printf("\n1.Prefix\n2.Suffix\n3.Is SubString??\n4.Exit...\n\n");
       scanf("%d",&a);

  switch(a)
  {
    case 1:
      //prefix
     for( i=0;i<n;i++)
    {
        for ( j=0;j<=i;j++)
        {
        printf("%c",string[j]);
        }
        printf("\n");
    }
    break;
    case 2:
    //suffix
     for( i=n-1;i>=0;i--)
    {
        for ( j=n-1;j>=i;j--)
        {
        printf("%c",string[j]);
        }
        printf("\n");
    }
    break;
    case 3:
    //substring
    printf("Enter string to check whether it's substring or not:");
    scanf("%s",&string1);
    if(strstr(string,string1)!=NULL)
    {
        printf("%s is a substring of %s.  \n",string1,string);
    }
    else
    {
        printf("%s is not a substring of %s.  \n",string1,string);
    }
    break;
    case 4:
    exit(0);
    break;
    default:
    printf("enter valid option!!!\n");
    break;
  }
       }while(a!=4);
return 0;
}
