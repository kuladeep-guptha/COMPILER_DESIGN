#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool isWhitespaceLine(const char *str) {
    while (*str) {
        if (!isspace(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

bool isComment(const char *str) {
    return (strstr(str, "//") == str);
}

int isKeyword(const char str[]) {
    if (strcmp(str, "if") ==0 || strcmp(str, "else")==0 ||
        strcmp(str, "while")==0 || strcmp(str, "do")==0 ||
        strcmp(str, "break")==0 ||
         strcmp(str, "continue")==0 || strcmp(str, "int")==0
        || strcmp(str, "double")==0 || strcmp(str, "float")==0
        || strcmp(str, "return")==0 || strcmp(str, "char")==0
        || strcmp(str, "case")==0 || strcmp(str, "char")==0
        || strcmp(str, "sizeof")==0 || strcmp(str, "long")==0
        || strcmp(str, "short")==0 || strcmp(str, "typedef")==0
        || strcmp(str, "switch")==0 || strcmp(str, "unsigned")==0
        || strcmp(str, "void")==0 || strcmp(str, "static")==0
        || strcmp(str, "struct")==0 || strcmp(str, "goto")==0 || strcmp(str, "for")==0||strcmp(str, "int")==0)
        return 1;
        
    return -1;
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return 1;
    return -1;
}

int isSpecial(char ch) {
    int sp = (int)ch;

    if ((sp >= 32 && sp <= 47) || (sp >= 58 && sp <= 64) || (sp >= 91 && sp <= 96) || (sp >= 123 && sp <= 126)) {
        return 1;
    }

    return -1;
}

int isConstant(char str) {
    if (str >= '0' && str <= '9')
        return 1;
    return -1;
}

void analyzeToken(const char token[]) {
    int len = strlen(token);
    char arr[100];
    int flag = 0, k = 0;

    for (int i = 0; i < len; i++) {
        arr[k] = token[i];
        k++;
        arr[k] = '\0';

        printf("%s\n", arr);
        if (isKeyword(arr) == 1) {
            printf(" %s is a Keyword\n", arr);
        
            flag = 1;
        } else if (isConstant(arr[k - 1]) == 1) {
            printf(" %c is a Constant\n", arr[k - 1]);
            flag = 1;
        } else if (isOperator(arr[k - 1]) == 1) {
            printf(" %c is an Operator\n", arr[k - 1]);

            if (arr[k - 1] == '=') {
                arr[k - 1] = '\0';
                k--;
                if (strlen(arr) != 0) {
                    printf("%s is an Identifier\n", arr);
                    flag = 1;
                }
            }
            flag = 1;
        } else if (isSpecial(arr[k - 1]) == 1) {
            printf(" %c is a Special character\n", arr[k - 1]);

            if (arr[k - 1] == '(' || arr[k - 1] == ')' || arr[k - 1] == ';' ) {
                arr[k - 1] = '\0';
                k--;
                if (strlen(arr) != 0 ) {
                    printf("%s is an Identifier\n", arr);
                    flag = 1;
                }
                
            }
            if( arr[k - 1] == '"')
            {
                arr[k - 1] = '\0';
                k--;
                if (strlen(arr) != 0 ) {
                    printf("%s is an String\n", arr);
                    flag = 1;
                }
            }
            flag = 1;
        }

        if (flag == 1) {
            k = 0;
            arr[k] = '\0';
            flag = 0;
        }
    }

    if (strlen(arr) != 0) {
        printf("%s is a String\n", arr);
    }
}

int main() {
    int tokens =0;
    FILE *inputFile;
    FILE *outputFile;
    FILE *outputAnalysis;

    char line[1000];

    inputFile = fopen("input.c", "r");
    outputFile = fopen("output.c", "w+");
    outputAnalysis = fopen("analysis.txt", "w+");

    if (inputFile == NULL || outputFile == NULL || outputAnalysis == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile) != NULL ) {
        if (!isWhitespaceLine(line) && !isComment(line)) {
            if (line[0] != '#') {
                char *token = strtok(line, "\t\n");
                while (token) {
                    fputs(token, outputFile);
                    token = strtok(NULL, "\t\n");
                }
                fputs("\n", outputFile);
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    outputFile = fopen("output.c", "r");

    char copy[1000];

    while (fgets(copy, sizeof(copy), outputFile) != NULL) {
        char *token = strtok(copy, " \t\n");
        
        while (token) {
            analyzeToken(token);
            token = strtok(NULL, " \t\n");
            tokens++;
        }
    }

    fclose(outputFile);
    fclose(outputAnalysis);
    printf("Total no.of tokens = %d \n",tokens);
    
    return 0;
}
