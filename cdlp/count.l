%{
#include<stdio.h>
int line=0,word=0,ch=0;
%}

%%
[a-z|A-Z|0-9] {ch++;}
" " {word++;}
"\n" {line++;word++;}
. {}
%%

void main(int argc,char *argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    printf("Word = %d\n",word);
    printf("Line = %d\n",line);
    printf("Character = %d\n",ch);
}