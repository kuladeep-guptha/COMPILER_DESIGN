#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
    FILE *fp;
    char str[100];
    fp=fopen("CFG.txt","r");
    if(fp==NULL){
        printf("File not found");
        return 0;
    }
    while(fgets(str,100,fp)!=NULL){
        printf("%s",str);
    }

}