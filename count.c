
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main(int argc, char *argv[])
// {
//     FILE *fp;
//     char ch[200];
//     int lines = 0, words = 0, characters = 0, vowels = 0, consonants = 0, digits = 0, other = 0;
//     fp = fopen(argv[1], "r");
//     if (fp == NULL)
//     {
//         printf("File not found");
//         return 0;
//     }
//     while (fgets(ch, 200, fp)!=NULL)
//     {
    
//         characters += strlen(ch);
//         for (int i = 0; i < strlen(ch); i++)
//         {
//             if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u' || ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'I' || ch[i] == 'O' || ch[i] == 'U')
//             {
//                 vowels++;
//             }
//             else if (ch[i] >= '0' && ch[i] <= '9')
//             {
//                 digits++;
//             }
//             else if ((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 'A' && ch[i] <= 'Z'))
//             {
//                 consonants++;
//             }
//             else if(ch[i]==10){
//                 lines++;
//                 other++;
//             }
//             else
//             {
//                 other++;
//             }
//         }
//         char *token = strtok(ch, " \n\t");
//          while (token!= NULL)
//         {
//             words++;
//             token = strtok(NULL, " \n\t");
//          }
         
//     }
//     printf("No.of lines: %d\n", lines);
//     printf("No.of words: %d\n", words);
//     printf("No.of characters: %d\n", characters);
//     printf("No.of vowels: %d\n", vowels);
//     printf("No.of consonants: %d\n", consonants);
//     printf("No.of digits: %d\n", digits);
//     printf("No.of other characters: %d\n", other);
//     fclose(fp);
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>

int candy(int* ratings, int ratingsSize){
    int n=ratingsSize;
    int amount=0;
    int ratings1[n];
    for(int i=0;i<n;i++){
        ratings1[i]=1;
    }
    for(int i=1;i<n;i++){
        if(ratings[i-1]>ratings[i] && i==1){
            while(ratings1[i-1]<=ratings1[i]){
                ratings1[i-1]++;
            }
        }
        if(ratings[i]>ratings[i-1] && i==n-1){
            while(ratings1[i]<=ratings1[i-1]){
                ratings1[i]++;
            }
        }
        if(ratings[i]>ratings[i-1] || ratings[i]>ratings[i+1]){
            if(ratings[i]>ratings[i-1]){
                while(ratings1[i]<=ratings1[i-1]){
                    ratings1[i]++;
                }
            }
            if(ratings[i]>ratings[i+1]){
                while(ratings1[i]<=ratings1[i+1]){
                    ratings1[i]++;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        amount=amount+ratings1[i];
    }
    return amount;
    

}
int main(){
    int n;
    printf("Enter the number of children: ");
    scanf("%d",&n);
    int ratings[n];
    printf("Enter the ratings of children: ");
    for(int i=0;i<n;i++){
        scanf("%d",&ratings[i]);
    }
    int amount=candy(ratings,n);
    printf("Minimum amount of candies required: %d",amount);
    return 0;
}