#include<stdio.h>
int main(){
    FILE *fp,*fp1;
    char ch[100];
    fp=fopen("input.txt","r");
    fp1=fopen("output.txt","w");
    if(fp==NULL || fp1==NULL){
        printf("File not found");
        return 0;
    }
    while(!feof(fp)){
        fgets(ch,2,fp);
        fputs(ch,fp1);
    }
    fclose(fp);
    fclose(fp1);
    return 0;

}