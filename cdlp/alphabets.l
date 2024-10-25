%{
#include<stdio.h>
int vowels=0,consonants=0;
%}

%%
[a|e|i|o|u|A|E|I|O|U] {vowels++;}
[b|c|d|f|g|h|j|k|l|m|n|p|q|r|s|t|v|w|x|y|z|B|C|D|F|G|H|J|K|L|M|N|P|Q|R|S|T|V|W|X|Y|Z] {consonants++;}
%%

void main(int argc,char *argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    printf("Vowels = %d\n",vowels);
    printf("Consonants = %d\n",consonants);
}