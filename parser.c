// create a parser tree for the given cfg
// S->AB|BC
// A->BA|a
// B->CC|b
// C->AB|a

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100];
const char *cursor;

int S();
int A();
int B();
int C();



int main()
{
    printf("enter the string\n");

    scanf("%s", str);
    cursor = str;
    if (S(str) && *cursor == '\0')
    {
        printf("accepted\n");
    }
    else
    {
        printf("rejected\n");
    }

    return 0;
}

int C(){
    if(A()){
        if(B()){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(*cursor=='a'){
        cursor++;
        return 1;
    }
    else{
        return 0;
    }

}

int B(){
    if(C()){
        if(C()){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(*cursor=='b'){
        return 1;
    }
    else{
        return 0;
    }
}


int A(){
    if(B()){
        if(A()){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(*cursor=='a'){
        cursor++;
        return 1;
    }
    else{
        return 0;
    }
}




int S()
{
    if(A()){
        if(B()){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(B()){
        if(C()){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
    
}

