#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_KEYWORDS 100
#define MAX_SPECIAL 100
#define MAX_OPERATORS 100

// Function to check if a character is a special character
bool isSpecial(char c, char special[][100], int specialCount) {
    for (int i = 0; i < specialCount; i++) {
        if (c == special[i][0]) {
            return true;
        }
    }
    return false;
}

// Function to check if a character is an operator
bool isOperator(char c, char operators[][100], int operatorCount) {
    for (int i = 0; i < operatorCount; i++) {
        if (c == operators[i][0]) {
            return true;
        }
    }
    return false;
}

// Function to check if a string is a valid identifier
int isValidIdentifier(char *str, char special[][100], int specialCount) {
    if (!isalpha(str[0])) {
        if(isdigit(str[0]))
        {
            for (int i = 1; i < strlen(str); i++) {
                if (!isdigit(str[i])) {
                    return 0;
                }
            }
            return 1;
        }
        return 0;
    }


    for (int i = 1; i < strlen(str); i++) {
        if (!isSpecial(str[i], special, specialCount)) {
            return 0;
        }
    }


    return 2;
}

int main() {
    FILE *fp;
    char buffer[100];
    char keywords[MAX_KEYWORDS][100];
    char special[MAX_SPECIAL][100];
    char operators[MAX_OPERATORS][100];
    char headers[MAX_OPERATORS][100];
    int keywordCount = 0, specialCount = 0, operatorCount = 0, headerCount=0;

    FILE *hd = fopen("header.txt", "r");
    while (fscanf(hd, "%s", headers[headerCount]) == 1) {
        headerCount++;
    }
    fclose(hd);

    // Read keywords from file
    FILE *kw = fopen("keywords.txt", "r");
    while (fscanf(kw, "%s", keywords[keywordCount]) == 1) {
        keywordCount++;
    }
    fclose(kw);

    // Read special characters from file
    FILE *sc = fopen("special.txt", "r");
    while (fscanf(sc, "%s", special[specialCount]) == 1) {
        specialCount++;
    }
    fclose(sc);

    // Read operators from file
    FILE *op = fopen("operators.txt", "r");
    while (fscanf(op, "%s", operators[operatorCount]) == 1) {
        operatorCount++;
    }
    fclose(op);

    fp = fopen("source.txt", "r");
    if (fp == NULL) {
        printf("Error opening file");
        return 0;
    }

    while (fscanf(fp, "%s", buffer) == 1) {
        int flag = 3; // 0 = keyword, 1 = special, 2 = operator, 3 = identifier, 4 = header

        // Check if the buffer is a keyword
        for (int i = 0; i < keywordCount; i++) {
            if (strcmp(buffer, keywords[i]) == 0) {
                printf("Keyword : %s\n", buffer);
                flag = 0;
                break;
            }
        }

        // Check if the buffer is a header
        for (int i = 0; i < headerCount; i++) {
            if (strcmp(buffer, headers[i]) == 0) {
                printf("Header : %s\n", buffer);
                flag = 4;
                break;
            }
        }

        // Check if the buffer is a special character
        if (flag == 3) {
            for (int i = 0; i < specialCount; i++) {
                if (strcmp(buffer, special[i]) == 0) {
                    printf("Special Character : %s\n", buffer);
                    flag = 1;
                    break;
                }
            }
        }

        // Check if the buffer is an operator
        if (flag == 3) {
            for (int i = 0; i < operatorCount; i++) {
                if (strcmp(buffer, operators[i]) == 0) {
                    printf("Operator : %s\n", buffer);
                    flag = 2;
                    break;
                }
            }
        }

        // Check if the buffer is an identifier
        if (flag == 3) {
            if (isValidIdentifier(buffer, special, specialCount) == 2) {
                printf("Identifier : %s\n", buffer);
            } 
            
            else if (isValidIdentifier(buffer, special, specialCount) == 1)
            {
                printf("Integer : %s\n", buffer);
            }

            else
            {
                printf("Invalid Identifier : %s\n",buffer);
            }
        }
    }

    fclose(fp);

    return 0;
}



/*
    INPUT FILE:
    # include < stdio.h >
    void main ()
    {
        int a , b ;
        a = 5 ;
    }
*/
