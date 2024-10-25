%{
    #include<stdio.h>
    int flag=0;
%}
%token NUMBER
%left '+''-'
%left '*''/''%'
%left '('')'
%%
ArithmeticExpression:E{
    printf("\nResult = %d\n",$$);
    return 0;
}
E:E'+'E{$$=$1+$3;}
|E'-'E{$$=$1-$3;}
|E'*'E{$$=$1*$3;}
|E'/'E{$$=$1/$3;}
|'('E')'{$$=$2;}
|NUMBER{$$=$1;}
;
%%
void main()
{
    printf("\nEnter any arithmetic expression which can have operations +,-,*,/,%,(,):");
    yyparse();
    if(flag==0)
    {
        printf("\nIt is Valid!\n");
    }
}
void yyerror()
{
    printf("\nInvalid!\n");
    flag=1;
}



Output:

Enter any arithmetic expression which can have operators: +,-,*,/,%,(,): 1+2

Result = 3
It is Valid!