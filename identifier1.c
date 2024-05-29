#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
void removecomment(FILE *fp,FILE *fp1){
    int flag=1;
     char ch[200];
     while(fgets(ch,200,fp)!=NULL){
         
        for(int i=0;i<strlen(ch);i++){
            if(ch[i]=='"' && flag==1){
                i++;
                printf("string=");
                while(ch[i]!='"'){
                    printf("%c",ch[i]);
                    i++;
                }
                printf("\n");
            }
           else {

            if(ch[i]=='#'){
                while(ch[i]!='\n'){
                    ch[i]='\0';
                    i++;
                }
            }
           if(ch[i]=='/' && ch[i+1]=='/'){
                while(ch[i]!='\n'){
                    ch[i]='\0';
                    i++;
                }
            }
            if(ch[i]=='/' && ch[i+1]=='*'){
                flag=0;
            }
            if(ch[i]=='*' && ch[i+1]=='/'){
                ch[i]='\0';
                ch[i+1]='\0';
                flag=1;
            }
            if(flag==0){
                ch[i]=' ';
            }
        }
        }
     
            fputs(ch,fp1);
        

     }


}

int isconstant(char ch){
    if(ch>='0' && ch<='9'){
        return 1;
    }
    return 0;
}

int isoperator(char ch){
     char *operators[] = {"+", "-", "*", "/",  ">", "<",  "="};
     
         for(int j=0;j<sizeof(operators)/sizeof(operators[0]);j++){
             if(ch==operators[j][0]){
                 return 1;
             }
                else{
                    return 0;
                }
         }
     
}
int iskeyword(char token[]){
    char *keywords[]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
        for(int j=0;j<sizeof(keywords)/sizeof(keywords[0]);j++){
            if(strcmp(token,keywords[j])==0){
                return 1;
            }
        }
        return 0;
    }

int isspecialcharacter(char ch){
    int sp = (int)ch;

    if ((sp >= 32 && sp <= 47) || (sp >= 58 && sp <= 64) || (sp >= 91 && sp <= 96) || (sp >= 123 && sp <= 126)) {
        return 1;
    }

    return 0;
}

int const_count=0;
    int keyword_count=0;
    int op_count=0;
    int spch_count=0;
    int id_count=0;

void count(char token[]){
    
    char ch[200];
    int f=0;
    int k=0;
    for(int i=0;i<strlen(token);i++){
        ch[k]=token[i];
        k++;
        ch[k]='\0';
        
        if(iskeyword(ch)==1){
            printf("keyword=%s\n",ch);
            f=1;
        }
        else if(isconstant(ch[k-1])){
            printf("constant=%c\n",ch[k-1]);
            f=1;
        }
        else if(isoperator(ch[k-1])){
            printf("operator=%c\n",ch[k-1]);
            if(ch[k-1]=='='){
                ch[k-1]='\0';
                k--;
                if(strlen(ch)!=0){
                    printf("identifier=%s\n",ch);
                    f=1;
                }
            }
            f=1;
        }
        else if(isspecialcharacter(ch[k-1])){
            printf("specialcharacter=%c\n",ch[k-1]);
            if(ch[k-1]=='(' || ch[k-1]==')' || ch[k-1]==';'){
                ch[k-1]='\0';
                k--;
                if(strlen(ch)!=0){
                    printf("identifier=%s\n",ch);
                   
                    f=1;
                }
            }
            if(ch[k-1]=='"'){
                ch[k-1]='\0';
                k--;
                if(strlen(ch)!=0){
                    f=1;
                }

            }
            
            f=1;
        }
        if(f==1){
            k=0;
            ch[k]='\0';
            f=0;
        }

    }
    
    

}



int main(int argc,char *argv[]){
   FILE *fp,*fp1,*fp2;
   
    fp=fopen(argv[1],"r");
    fp1=fopen("output.c","w");
    if(fp==NULL){
        printf("File not found");
        return 0;
    }
    removecomment(fp,fp1);
    fclose(fp);
    fclose(fp1);
    fp2=fopen("output.c","r");
    char ch[200];
    while(fgets(ch,200,fp2)!=NULL){
        char *token=strtok(ch," \t\n");
        while(token){
            count(token);
            token=strtok(NULL," \t\n");
        }
    }
   
    fclose(fp2);


    return 0;


    
}