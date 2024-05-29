#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char first_terminals[100];
char first_nonterminals[100][100];
char follow[100][100];

int isPresent(char a[100], char ch, int n);
int find_index(char ch);
void printfirst();
void initialise_first(char nt[100], char t[100], int n, int m);
void computeFirst(char cfg[100][100], int n, int m);
int set_union(char *src, char *dest, int changed);
char* removeepsilon(char first[]);
int isepsilon(char string[]);
int set_union1(char *src, char dest, int changed);
int find_index1(char ch);
void initialise_follow(char nt[100],char t[100],int n,int m);
void printfollow();


int main()
{
    FILE *fp;
    char str[100];
    char cfg[100][100];
    char nt[100];
    char t[100];
    int l = 0, k = 0, max = 0, len = 0, m = -1, n = 0;

    fp = fopen("CFG.txt", "r");

    while (fgets(str, 50, fp) != NULL)
    {
        len = 0;
        m++;
        // printf("%d\n", m);
        n = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] >= 65 && str[i] <= 90)
            {
                if (!isPresent(nt, str[i], l))
                {
                    nt[l] = str[i];
                    l++;
                }
                cfg[m][n] = str[i];
                n++;
            }
            if (str[i] >= 97 && str[i] <= 122)
            {
                if (!isPresent(t, str[i], k))
                {
                    t[k] = str[i];
                    k++;
                }
                cfg[m][n] = str[i];
                n++;
            }
            if (str[i] == '$')
            {
                if (!isPresent(t, '$', k))
                {
                    t[k] = str[i];
                    k++;
                }
                cfg[m][n] = str[i];
                n++;
            }
            if (str[i] == '#')
            {
                if (!isPresent(t, '#', k))
                {
                    t[k] = str[i];
                    k++;
                }
                cfg[m][n] = str[i];
                n++;
            }
            len++;
        }

        if (len >= max)
        {
            max = len;
        }
    }

    int non_terminals = l, terminals = k;

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < max; j++)
        {
            printf(" %c ", cfg[i][j]);
        }
        printf("\n");
    }

    initialise_first(nt, t, non_terminals, terminals);
    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            printf("%c ",first_terminals[i]);
        }
        printf("\n");
    }
    printf("k=%c\n",first_terminals[1]);
    computeFirst(cfg,m+1,max);
    printfirst();
    computefollow(cfg,m+1,max);
    printfollow();



    return 0;
}

int isPresent(char a[100], char ch, int n)
{
    if (n == 0)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (ch == a[i])
        {
            return 1;
        }
    }

    return 0;
}

int find_index(char ch)
{
    if (ch >= 65 && ch <= 90)
    {
        for (int i = 0; i < 10; i++)
        {
            if (ch == first_nonterminals[i][0])
            {
                return i;
            }
        }
    }
    if (ch >= 97 && ch <= 122)
    {
        for (int i = 0; i < 10; i++)
        {
            if (ch == first_terminals[i])
            {
                return i;
            }
        }
    }
    if (ch == '#')
    {
        for (int i = 0; i < 10; i++)
        {
            if (ch == first_terminals[i])
            {
                return i;
            }
        }
    }
}
int find_index1(char ch){
    for(int i=0;i<10;i++){
        if(follow[i][0]==ch){
            return i;
        }
    }
}
void initialise_first(char nt[100], char t[100], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        first_terminals[i] = t[i];
        
    }

    for (int i = 0; i < n; i++)
    {
        first_nonterminals[i][0] = nt[i];
        first_nonterminals[i][1] = ' ';
    }
}

void initialise_follow(char nt[100],char t[100],int n,int m){
    for(int i=0;i<m;i++){
        follow[i][0]=t[i];
        follow[i][1]=' ';
    }
    for(int i=0;i<n;i++){
        follow[i][0]=nt[i];
        if(i==0){
            follow[i][1]='$';
        }
        else{
       
        follow[i][1]=' ';
        }
    }



}

void computeFirst(char cfg[100][100], int n, int m)
{
    int changing = 1;
    int index = 0;

    while (changing)
    {
        changing = 0;
        for (int i = 0; i < n; i++)
        {
            index = find_index(cfg[i][0]);

            int h = strlen(cfg[i]) - 1;
            int x_index = find_index(cfg[i][1]);

            char *x_first;
            if (cfg[i][1] >= 65 && cfg[i][1] <= 90)
            {
                x_first = removeepsilon(first_nonterminals[x_index]);

                changing = set_union(first_nonterminals[index], x_first,changing);

                int j = 1;

                while (isepsilon(first_nonterminals[x_index]) && j <= h - 1)
                {
                    j++;
                    x_index = find_index(cfg[i][j]);
                    x_first = removeepsilon(first_nonterminals[x_index]);
                    changing = set_union(first_nonterminals[index], x_first,changing);
                }

                if (j == h)
                {
                    char *epsilon = "#";
                    changing = set_union(first_nonterminals[index], epsilon,changing);
                }
            }
            else
            {              
                changing = set_union1(first_nonterminals[index],first_terminals[x_index] ,changing);
            }
        }
    }
}
void computefollow(char cfg[100][100],int n,int m){
    initialie_follow();
    int changing=1;
    while(changing){
        changing=0;
        for(int i=0;i<n;i++){
           int index=find_index1(cfg[i][0]);
           int h=strlen(cfg[i])-1;
           int x_index=find_index(cfg[i][h]);
           changing=set_union(follow[x_index],follow[index],changing);
           char *rest=follow[index];
           for(int j=h;j<=2;j--){
            if(cfg[i][j]<=65 && cfg[i][j]>=90){
                int index1=find_index1(cfg[i][j]);
                int index2=find_index1(cfg[i][j-1]);
                if(isepsilon(first_nonterminals[index1]))
                {
                    char *string1=removeepsilon(first_nonterminals[index1]);
                    changing=set_union(follow[index2],string1,changing);
                    changing=set_union(follow[index2],rest,changing);
                    rest=follow[index2];
                }
                else{
                    changing=set_union(follow[index2],first_nonterminals[index1],changing);
                    rest=follow[index2];
                }

            }
            else if(cfg[i][j]>=97 && cfg[i][j]<=122){
                int index1=find_index1(cfg[i][j]);
                int index2=find_index1(cfg[i][j-1]);
                if(isepsilon(first_terminals[index1]))
                {
                    char *string1=removeepsilon(first_terminals[index1]);
                    changing=set_union(follow[index2],string1,changing);
                    changing=set_union(follow[index2],rest,changing);
                    rest=follow[index2];
                }
                else{
                    changing=set_union(follow[index2],first_terminals[index1],changing);
                    rest=follow[index2];
                }


            }
            
           }


        }
    }


}
int set_union(char *src, char *dest, int changed)
{
    int l = strlen(src);
    for(int i = 0; i < strlen(dest); i++)
    {
        if(strchr(src, dest[i]) == NULL)
        {
            src[l] = dest[i];
            changed = 1;
            l++;
        }
    }
    return changed;
}
int set_union1(char *src, char dest, int changed)
{
    int l = strlen(src);
    
        if(strchr(src, dest) == NULL)
        {
            src[l] = dest;
            changed = 1;
            l++;
        }
    
    return changed;
}

char* removeepsilon(char first[])
{
    char * string = (char *)malloc(sizeof(char) * strlen(first));
    int l = strlen(first), j = 0;
    for(int i = 1; i < l; i++)
    {
        if(first[i] != '#')
            string[j] = first[i];
        j++;
    }
    return string;
}
void printfirst(){
    for(int i=0;i<5;i++){
       
        printf(" First( %c ) : { %c } ",first_terminals[i], first_terminals[i]);
        
        printf("\n");
    }
    for(int i=0;i<4;i++){
        printf(" First( %c ) : { ", first_nonterminals[i][0]);
        for(int j=2;j<6;j++){
            printf(" %c ",first_nonterminals[i][j]);
        }
        printf(" } \n");
    }

}
void printfollow(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%c",follow[i][j]);
        }

    }
}

int isepsilon(char string[])
{
    for(int i = 0; i < strlen(string); i++)
        if(string[i] == '#')
            return 1;
    return 0;
}