// V = S$
//  S = aAS
//  S = c
//  A = ba
//  A = SB
//  B = bA
//  B = S
// LL(1) Parsing Table

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compute(char t,char nt,char cfg[100][100]);

int main()
{

    FILE *fp;
    int terminal_count = 0;
    int non_terminal_count = 0;
    int count1 = 0;
    char ter[100];
    char non_ter[100];
    char str[100];
    fp = fopen("CFG.txt", "r");
    int max = 0;
    int x=0,j=0,k=0;
    // char **output = (char **)malloc(sizeof(char *) * 100);
    // while(fgets(str, 50, fp) != NULL) {
    //    // printf("%s",str);
    //     str[strlen(str)-1] = '\0';
    //     output[x] = (char *)malloc(strlen(str) + 1);
    //     strcpy(output[x], str);
    //     x++;
    // }
    // fp =NULL;
    // fp =fopen("CFG.txt","r");

    while (fgets(str, 200, fp) != NULL)
    { 
        count1++;
        int len = 0;

        for (int i = 0; i < strlen(str); i++)
        {
        
            if (str[i] <= 90 && str[i] >= 65)
            {
                non_ter[j] = str[i];
                j++;
                len++;
            }
            if ((str[i] <= 122 && str[i] >= 97) || str[i] == '$')
            {
                ter[k] = str[i];
                k++;
                len++;
            }
        }
        if (len >= max)
        {
            max = len;
        }
    }
    
    for (int i = 0; i < strlen(ter); i++)
    {
        for (int j = i + 1; j < strlen(ter); j++)
        {
            if (ter[i] == ter[j])
            {
                ter[j] = '0';
            }
        }
    }
    for (int i = 0; i < strlen(non_ter); i++)
    {
        for (int j = i + 1; j < strlen(non_ter); j++)
        {
            if (non_ter[i] == non_ter[j])
            {
                non_ter[j] = '0';
            }
        }
    }
    for (int i = 0; i < strlen(ter)-1; i++)
    {
        if (ter[i] != '0')
        {
            terminal_count++;
        }
    }
    for (int i = 0; i < strlen(non_ter)-1; i++)
    {
        if (non_ter[i] != '0')
        {
            non_terminal_count++;
        }
    }

    char arr[100][100];
    for(int i=0;i<count1;i++){
        for(int j=0;j<max+1;j++){
            arr[i][j]=' ';
        }
    }
    rewind(fp);
    int i = 0;
    char ch[200];
    while (fgets(ch, 200, fp) != NULL)
    {
        int k = 0;
        for (int j = 0; j < strlen(ch); j++)
        {
            if (ch[j] <= 90 && ch[j] >= 65 || ch[j] == '$' || ch[j] >= 97 && ch[j] <= 122)
            {
                arr[i][k] = ch[j];
                k++;
            }
        }
        i++;
    }

    for(int i=0;i<count1;i++){
        for(int j=0;j<max+1;j++){
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }


    j=0;
    char z[non_terminal_count];
    char y[terminal_count];
    for(int i=0;i<strlen(non_ter)-1;i++){
        printf("%c ",non_ter[i]);
        if(non_ter[i]!='0'){
        z[j]=non_ter[i];
        j++;
        }
    }
    printf("\n");
    j=0;
    for(int i=0;i<strlen(ter)-1;i++){
        printf("%c ",ter[i]);
        if(ter[i]!='0'){
        y[j]=ter[i];
        j++;
        }
    }
    printf("\n");

printf("%d %d\n",non_terminal_count,terminal_count);
for(int i=0;i<non_terminal_count;i++){
    printf("%c ",z[i]);
}
printf("\n");
for(int i=0;i<terminal_count;i++){
    printf("%c ",y[i]);
}
printf("\n");


     
    char parsing_table[non_terminal_count][terminal_count];
    
    for(int m=0;m<non_terminal_count;m++){
        for(int n=0;n<terminal_count;n++){
            parsing_table[m][n]=compute(y[m],z[n],arr);
        }
    }
    // printf("count1=%d\n",count1);
    // parsing_table[0][0]=compute(y[0],z[0],arr);

    for(int m=0;m<non_terminal_count;m++){
        for(int n=0;n<terminal_count;n++){
            printf("%d ",parsing_table[m][n]);
        }
        printf("\n");
    }
    
    // for(int m=0;m<non_terminal_count;m++){
    //     for(int n=0;n<terminal_count;n++){
    //         int s=parsing_table[m][n];
            
    //             for(int i=0;i<max;i++){
    //                 if(arr[s][i]==' '){
    //                     break;
    //                 }
    //                 printf("%c",arr[s][i]);
    //                 if(i==0){
    //                     printf("->");
    //                 }
                   
    //             }
    //             printf("\n");

            
            
    //     }
    //     printf("\n");
    // }
    
    



    return 0;
}


int compute(char t,char nt,char cfg[100][100])
{
    int r=7;
    printf("r=%d \n",r);
    printf("t=%c nt=%c\n",t,nt);
    // for(int i=0;i<r;i++){
    //     printf("hi=%c ",cfg[i][0]);
    //     printf("%c \n",cfg[i][1]);
    // }

    int ans=-1;


    for(int i=0;i<r;i++)
    {
        printf("hello2\n");
        printf("%c nt=%c \n",cfg[i][0],nt);
        if(cfg[i][0]==nt )
        {
            printf("hello1\n");
            if(cfg[i][1]==t)
                {
                    printf("yes\n");
                    return i;
                    break;
                }
                
            else{
                printf("hello\n");
             ans= compute(t,cfg[i][1],cfg);
             if(ans != -1)
             {
                return i;
                
             }
                
            
            }
        }
        

    }
    if (ans != -1)
    return ans;

    return -1;
}