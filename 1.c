#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>

bool emptyline(const char *str) {
    while (*str) {
        if (!isspace(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

bool comment(const char *str) {
    return (strstr(str, "//") == str);
}

int keyword(char str[])
{
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

int Identifier()
{

}

int Operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return 1;
    return -1;
}

int special(char ch)
{
    int sp=(int)ch;

    if((sp>=32 && sp<=47)||(sp>=58 && sp<=64)||(sp>=91 && sp<=96)||(sp>=123 && sp<=126))
    {
        return 1;
    }

    return -1;
}

int constant(char str)
{
    if (str == '0' || str == '1' || str == '2'
        || str == '3' || str == '4' || str == '5'
        || str == '6' || str == '7' || str == '8'
        || str == '9')
        return 1;
    
    return -1;
}

bool check(char ch[])
{
    int len=strlen(ch);

    char arr[100];

    int flag=0,k=0;

    for(int i=0;i<len;i++)
    {
        arr[k]=ch[i];
        k++;
        arr[k] = '\0';
        
        if(keyword(arr)==1)
        {
            
            printf(" %s is Keyword\n ",arr);
            flag=1;
        }
        else if(constant(arr[k-1])==1)
        {
            printf(" %c is an Constant\n ",arr[k-1]);
            flag=1;
        }
        else if(Operator(arr[k-1])==1)
        {
            printf(" %c is an Operator\n ",arr[k-1]);

            if(arr[k-1]=='=')
            {
                arr[k-1]='\0';
                k--;
                if(strlen(arr)!=0){
                    printf("%s is an Identifier\n",arr);
                    flag=1;
                }   
            }
            flag=1;
        }
        else if(special(arr[k-1])==1)
        {
            printf(" %c is an special character \n ",arr[k-1]);
            
            if(arr[k-1]=='('||arr[k-1]==')'||arr[k-1]==';'||arr[k-1]=='"')
            {
                arr[k-1]='\0';
                k--;
                if(strlen(arr)!=0){
                    printf("%s is an Identifier\n",arr);
                    flag=1;
                }   
            }
            flag=1;
        }

        if(flag==1)
        {
            k=0;
            arr[k] ='\0';
            flag=0;
        }
    }

    if(strlen(arr)!=0)
    {
        printf("%s is String\n",arr);
    }
}

int main()
{
    FILE* f1;
    FILE* f2;
    FILE* f3;

    char data[1000];

    f1=fopen("input.c","r");

    f2=fopen("output.c","w+");

    if (f1 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while(1)
    {
        fgets(data,sizeof(data),f1);

        if(feof(f1))
        break;

        if(!emptyline(data) && !comment(data))
        {
            if(data[0]!='#')
            {
                char *tok = strtok(data, "\t\n"); 
                while (tok) 
                {
                    fputs(tok,f2);
                    tok = strtok(NULL, "\t\n");
                }
                fputs("\n",f2); 
            }    
        }
    }

    fclose(f1);
    fclose(f2);

    f2 = fopen("output.c", "r");

    char copy[1000];

    while(1)
    {
        fgets(copy,sizeof(data),f2);

        if(feof(f2))
        break;

        char *tok = strtok(copy, " \t\n"); 
        while (tok) 
        {
            check(tok);
            tok = strtok(NULL, " \t\n");
        }     
    }


    return 0;
}