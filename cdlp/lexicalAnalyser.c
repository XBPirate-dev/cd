#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	char A[100];
	FILE*fp;
	int i, len;
	fp=fopen("lexFile.txt","r");
	while(fscanf(fp,"%s",A)!=EOF)
	{	
		if(strcmp(A,"int")==0||strcmp(A,"char")==0||strcmp(A,"float")==0||strcmp(A,"double")==0)
		{
		  printf("%s\t : keyword\n",A);		  
		}
		else if(isalpha(A[0]))
		{
		 printf("%s\t : identifier\n",A);
		}
		else if(isdigit(A[0]))
		{
		 printf("%s\t : constant\n",A);
		}
		else if(strcmp(A,"+")==0||strcmp(A,"-")==0||strcmp(A,"*")==0||strcmp(A,"/")==0||strcmp(A,"=")==0)
		{
		  printf("%s\t : operator\n",A);
		}
		else if(strcmp(A,";")==0||strcmp(A,",")==0||strcmp(A,"[")==0||strcmp(A,"]")==0)
		{
		  printf("%s\t : special symbol\n",A);
		}				
	}fclose(fp);	
}
/*
--------------lexFile.txt----------------
int a , b , c ;
a = 10 ;
b = 7 ;
d = a + b ;
char arr [ 10 ] ;
--------------output----------------------
int	 : keyword
a	 : identifier
,	 : special symbol
b	 : identifier
,	 : special symbol
c	 : identifier
;	 : special symbol
a	 : identifier
=	 : operator
10	 : constant
;	 : special symbol
b	 : identifier
=	 : operator
7	 : constant
;	 : special symbol
d	 : identifier
=	 : operator
a	 : identifier
+	 : operator
b	 : identifier
;	 : special symbol
char	 : keyword
arr	 : identifier
[	 : special symbol
10	 : constant
]	 : special symbol
;	 : special symbol
*/
