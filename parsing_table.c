#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compute_rule(char t, char nt, char cfg[100][100], int r)
{
    int ans = -1;
    for (int i = 0; i < r; i++)
    {
        if (cfg[i][0] == nt)
        {
            if (cfg[i][1] == t)
                return i;
            else
            {
                ans = compute_rule(t, cfg[i][1], cfg, r);
                if (ans != -1)
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

int main()
{
    FILE *file_ptr;
    file_ptr = fopen("cfg1.txt", "r");

    char terminals[100], non_terminals[100];

    int terminal_count = 0, non_terminal_count = 0, temp = 0, j = 0, i = 0;
    char cfg[100][100];

    char input_line[100];
    printf("Given Input CFG :\n");
    int line_count = 0;
    char **output = (char **)malloc(sizeof(char *) * 100);
    while (fgets(input_line, 50, file_ptr) != NULL)
    {
        printf("%s", input_line);
        if (input_line[strlen(input_line) - 1] == '\n')
            input_line[strlen(input_line) - 1] = '\0';
        output[line_count] = (char *)malloc(strlen(input_line) + 1);
        strcpy(output[line_count], input_line);
        line_count++;
    }
    fclose(file_ptr);
    file_ptr = NULL;
    file_ptr = fopen("CFG.txt", "r");
    while (fgets(input_line, 50, file_ptr) != NULL)
    {
        non_terminal_count = 0;

        for (int z = 0; z < strlen(input_line); z++)
        {
            if (input_line[z] >= 65 && input_line[z] <= 90)
            {
                cfg[terminal_count][non_terminal_count] = input_line[z];
                non_terminal_count++;
                temp = 0;
                for (int k1 = 0; k1 < j; k1++)
                {
                    if (non_terminals[k1] == input_line[z])
                    {
                        temp = 1;
                        break;
                    }
                }
                if (temp == 0)
                {
                    non_terminals[j] = input_line[z];
                    j++;
                }
            }
            else if (input_line[z] >= 97 && input_line[z] <= 122)
            {
                cfg[terminal_count][non_terminal_count] = input_line[z];
                non_terminal_count++;
                temp = 0;
                for (int k1 = 0; k1 < i; k1++)
                {
                    if (terminals[k1] == input_line[z])
                    {
                        temp = 1;
                        break;
                    }
                }
                if (temp == 0)
                {
                    terminals[i] = input_line[z];
                    i++;
                }
            }
            else if (input_line[z] == '$')
            {
                cfg[terminal_count][non_terminal_count] = input_line[z];
                non_terminal_count++;
                for (int k1 = 0; k1 < i; k1++)
                {
                    if (terminals[k1] == input_line[z])
                    {
                        temp = 1;
                        break;
                    }
                }
                if (temp == 0)
                {
                    terminals[i] = input_line[z];
                    i++;
                }
            }
        }
        terminal_count++;
    }

    
    printf("\nParsing table for the given cfg :\n");
    int parsing_table[i][j];
    printf("\t\t");
    for (int m = 0; m < i; m++)
    {
        printf("%c\t\t", terminals[m]);
    }
    printf("\n");
    for (int m = 0; m < j; m++)
    {
        for (int n = 0; n <= i; n++)
        {
            if (n == 0)
            {
                printf("%c\t\t", non_terminals[m]);
            }
            else
            {
                parsing_table[m][n] = compute_rule(terminals[n - 1], non_terminals[m], cfg, terminal_count);
                if (parsing_table[m][n] != -1)
                {
                    printf("%s\t\t", output[(parsing_table[m][n])]);
                }
                else
                    printf("-1\t\t");
            }
        }
        printf("\n");
    }
    return 0;
}
