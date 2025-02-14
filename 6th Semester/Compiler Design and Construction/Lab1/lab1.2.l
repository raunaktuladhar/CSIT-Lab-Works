%{
#include<stdio.h>
%}
%%
bool|int|float printf("Keyword");
[-,+]?[0-9]+ printf("Constants");
[,.'"]+ printf("Punctuation Chars");
[!@#$%^&*()]+ printf("Special Chars");
[a-zA-Z]+ printf("Identifiers");
%%
int main()
{
	yylex();
}

int yywrap() {
    return 1;  // Indicating that there's no more input to process
}


