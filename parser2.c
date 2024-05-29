/*
S → 0A | 1B | $
A → 0S | 1C 
B → 1S | 0C 
C → 0B | 1A
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * str;

int S();
int A();
int B();
int C();

int main() {
    char string[64];

    printf("Enter the string : ");
    scanf("%s",string);

    str = string;
    int x = S();

    if(x==1 && *str == '\0') {
        printf("Accepted\n");
    }
    else {
        printf("rejected\n");
    }

    return 0;
}

int S() {
    if(*str == '0') {
        str++;
        if(A()) {
            return 1;
        }
        return 0;
    }
    else if(*str == '1') {
        str++;
        if(B()) {
            return 1;
        }
        return 0;
    }
    else {
        return 1;
    }
}

int A() {
    if(*str == '0') {
        str++;
        if(S()) {
            return 1;
        }
        return 0;
    }
    if(*str == '1') {
        str++;
        if(C()) {
            return 1;
        }
        return 0;
    }
}

int B() {
    if(*str == '1') {
        str++;
        if(S()) {
            return 1;
        }
        return 0;
    }
    if(*str == '0') {
        str++;
        if(C()) {
            return 1;
        }
        return 0;
    }
}

int C() {
    if(*str == '0') {
        str++;
        if(B()) {
            return 1;
        }
        return 0;
    }
    if(*str == '1') {
        str++;
        if(A()) {
            return 1;
        }
        return 0;
    }
}