%{
#include<stdio.h>
char string;
%}

%%
abc       { printf("ABC"); }
%%

void main(int argc,char *argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    printf("\n");
}