#include<stdio.h>
int main(){
    FILE *fp;
    char ch[100];
    fp=fopen("output.txt","a");
    if(fp==NULL){
        printf("File not found");
        return 0;
    }
    printf("Enter a string: ");
    gets(ch);
    fputs(ch,fp);
    fclose(fp);
    return 0;
    

}