#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *fp;
    fp=fopen("CFG.txt","r");
    char str[100];
    while(fgets(str,200,fp)!=NULL){
        printf("%s\n",str);
        char *token=strtok(str," /n/t");
          while (token != NULL) {
        printf("t=%s\n", token);
        token = strtok(NULL, " /n/t");
    }

    }

}