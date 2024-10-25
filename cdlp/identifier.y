%{
    #include<stdio.h>
%}
%token DIGIT LETTER
%%
stmt:A;
A:LETTER B;
B:/* empty*/ |LETTER B|DIGIT B;
%%
void main()
{
    printf("Enter the string\n");
    yyparse();
    printf("Valid\n");
    exit(0);
}
void yyerror()
{
    printf("Invalid\n");
    exit(0);
}


Output:

Enter the string:
hello
Valid

Enter the string:
1hello
Invalid

Enter the string:
two sum
Invalid

