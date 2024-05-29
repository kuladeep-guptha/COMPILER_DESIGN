#include<stdio.h>
int main()
{
    FILE *fp;
    char string[300];
    fp=fopen("input.txt","r");
     if(fp==NULL)
     {
         printf("File not found");
         return 0;
     }
    while(!feof(fp)){
        fgets(string,2,fp);
        printf("%s",string);
    }
    fclose(fp);
    return 0;
}