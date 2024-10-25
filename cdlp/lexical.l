%{
#include<stdio.h>
int keywords=0,identifier=0,special=0,operator=0,integer=0;
char buffer[100];
%}

%%
[stdio.h|string.h] {printf("Header: %s\n",yytext);}
[auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while] {
    printf("Identifier : %s\n",yytext);
    identifier++;}
[+|-|=|%|*|^|/|<|>] {
    printf("Operator : %s\n",yytext);
    operator++;}
[{|{|(|:|"|?|,|.|)|}|}|&|||$|#|;] {
    printf("Special Character : %s\n",yytext);
    special++;}
[a-zA-Z_][a-zA-Z0-9_]* {
    printf("Keyword : %s\n",yytext);
    keywords++;
}
[0-9] {
    printf("Integer : %s\n",yytext);
    integer++;
}
%%

void main(int argc,char *argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    // printf("Keywords = %d\n",keywords);
    // printf("Operators = %d\n",operator);
    // printf("Special Characters = %d\n",special);
    // printf("Identifiers = %d\n",identifier);
    // printf("Integers = %d\n",integer);
}