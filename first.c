#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char nonTerminal;
    char production[MAX][MAX];
    int noOfProductions;
} ProductionRule;

typedef struct {
    char startSymbol;
    char nonTerminals[MAX];
    char terminals[MAX];
    ProductionRule rules[MAX];
    int noOfRules;
} ContextFreeGrammar;

typedef struct {
    char symbol;
    char first[MAX];
    char follow[MAX];
} FirstFollowSet;

ContextFreeGrammar cfg;
FirstFollowSet table[MAX];

void printTerminals()
{
    printf("Terminals    : {");
    for(int i = 0; i < strlen(cfg.terminals) - 1; i++)
        printf("%c, ", cfg.terminals[i]);
    printf("%c}\n", cfg.terminals[strlen(cfg.terminals) - 1]);
}

void printNonTerminals()
{
    printf("Non Terminals: {");
    for(int i = 0; i < strlen(cfg.nonTerminals) - 1; i++)
        printf("%c, ", cfg.nonTerminals[i]);
    printf("%c}\n", cfg.nonTerminals[strlen(cfg.nonTerminals) - 1]);
}

void printCFG()
{
    printf("Context-Free Grammar:\n");
    printf("Start Symbol : %c\n", cfg.startSymbol);
    printNonTerminals();
    printTerminals();
    printf("Production Rules:\n");
    for(int i = 0; i < strlen(cfg.nonTerminals); i++)
    {
        printf("\t%c -> ", cfg.rules[i].nonTerminal);
        for(int j = 0; j < cfg.rules[i].noOfProductions - 1; j++)
        {
            printf("%s | ", cfg.rules[i].production[j]);
        }
        printf("%s", cfg.rules[i].production[cfg.rules[i].noOfProductions - 1]);
        printf("\n");
    }
    printf("\n");
}

int insertNonTerminal(char nonTerm)
{
    if(strchr(cfg.nonTerminals, nonTerm) == NULL)
    {
        cfg.nonTerminals[strlen(cfg.nonTerminals)] = nonTerm;
        return 0;
    }
    return 1;
}

void insertTerminal(char letter)
{
    if(strchr(cfg.terminals, letter) == NULL)
        cfg.terminals[strlen(cfg.terminals)] = letter;
}

void printTable(ProductionRule table[][MAX], int numNonTerminals, int numTerminals)
{
    printf("LL(1) Parsing Table:\n");
    printf("\t\t");
    for(int i = 0; i < numTerminals; i++)
    {
        printf("%c\t\t", cfg.terminals[i]);
    }
    printf("\n");
    for(int i = 0; i < numNonTerminals; i++)
    {
        printf("\t%c\t", cfg.nonTerminals[i]);
        for(int j = 0; j < numTerminals; j++)
        {
            if(table[i][j].production[0][0] != '\0')
                printf("%c->%s\t\t", cfg.nonTerminals[i], table[i][j].production[0]);
            else
                printf("\t\t");
        }
        printf("\n");
    }
}

int getIndexInTable(FirstFollowSet table[], char symbol, int numSymbols)
{
    for(int i = 0; i < numSymbols; i++)
        if(table[i].symbol == symbol)
            return i;
    printf("Trying to find index of %c in ", symbol);
    printNonTerminals();
    exit(1);
}

int isEpsilon(char string[])
{
    for(int i = 0; i < strlen(string); i++)
        if(string[i] == '#')
            return 1;
    return 0;
}

char* removeEpsilon(char first[])
{
    char *string = (char*)malloc(sizeof(char) * MAX);
    int l = strlen(first), j = 0;
    for(int i = 0; i < l; i++)
    {
        if(first[i] != '#')
            string[j] = first[i];
        j++;
    }
    return string;
}

int unionOfSets(char *src, char *dest, int changed)
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

void printFirstSets(FirstFollowSet table[], int numSymbols)
{
    printf("First-Sets:\n");
    for(int i = 0; i < numSymbols; i++)
    {
        printf("\tFIRST(%c) = { ", table[i].symbol);
        for(int j = 0; j < strlen(table[i].first) - 1; j++)
            printf("%c, ", table[i].first[j]);
        printf("%c }\n", table[i].first[strlen(table[i].first) - 1]);
    }
}

void printFollowSets(FirstFollowSet table[], int numSymbols)
{
    printf("\nFollow-Sets:\n");
    for(int i = 0; i < numSymbols; i++)
    {
        printf("\tFOLLOW(%c) = { ", table[i].symbol);
        int n = strlen(table[i].follow);
        for(int j = 0; j < n - 1; j++)
            printf("%c, ", table[i].follow[j]);
        printf("%c }\n", table[i].follow[n - 1]);
    }
}

void calculateFirstSets(ContextFreeGrammar cfg)
{
    int numNonTerminals = strlen(cfg.nonTerminals);
    int numTerminals = strlen(cfg.terminals);
    int numSymbols = numNonTerminals + numTerminals;

    for(int i = 0; i < numTerminals; i++)    // for each (a ∈ T) FIRST(a) = {a}; FIRST(#) = {#}; # = epsilon
    {
        table[i].symbol = cfg.terminals[i];
        table[i].first[0] = cfg.terminals[i];
    }
    for(int i = numTerminals; i < numSymbols; i++)  // for each (A ∈ N) FIRST(A) = ∅
    {
        table[i].symbol = cfg.nonTerminals[i - numTerminals];
        strcpy(table[i].first, "");
    }
    int changing = 1;
    while(changing)
    {
        changing = 0;
        for(int i = 0; i < cfg.noOfRules; i++)
        {
            for(int j = 0; j < cfg.rules[i].noOfProductions; j++)
            {
                char nonTerminal = cfg.rules[i].nonTerminal;

                char prod[MAX];
                strcpy(prod, cfg.rules[i].production[j]);

                int index = getIndexInTable(table, nonTerminal, numSymbols);
                int k = 0, n = strlen(prod), forFirstX = 1;

                int xIndex = getIndexInTable(table, prod[k], numSymbols);
                while((isEpsilon(table[xIndex].first) && k <= n - 2) || forFirstX)
                {
                    if(forFirstX)
                    {
                        forFirstX = 0;
                        k = -1;
                    }
                    xIndex = getIndexInTable(table, prod[k + 1], numSymbols);
                    char *xFirstSet = removeEpsilon(table[xIndex].first);
                    changing = unionOfSets(table[index].first, xFirstSet, changing);
                    k++;
                }
                if(k == n - 1 && isEpsilon(table[xIndex].first))
                {
                    char *epsilon = "#";
                    changing = unionOfSets(table[index].first, epsilon, changing);
                }
            }
        }
    }
    printFirstSets(table, numSymbols);
}

void calculateFollowSets(ContextFreeGrammar cfg)
{
    int numNonTerminals = strlen(cfg.nonTerminals);
    int numTerminals = strlen(cfg.terminals);
    int numSymbols = numNonTerminals + numTerminals;

    for(int i = 0; i < numTerminals; i++)    // for each (a ∈ T) FIRST(a) = ∅
    {
        table[i].symbol = cfg.terminals[i];
        strcpy(table[i].follow, "");
    }
    for(int i = numTerminals; i < numSymbols; i++)  // for each (A ∈ N) FOLLOW(A) = ∅
    {
        table[i].symbol = cfg.nonTerminals[i - numTerminals];
        strcpy(table[i].follow, "");
    }
    for(int i = 0; i < numSymbols; i++)    // FOLLOW(S) = {$}
    {
        if(table[i].symbol == cfg.startSymbol)
            table[i].follow[0] = '$';
    }
    int changing = 1;
    while(changing)
    {
        changing = 0;
        for(int i = 0; i < cfg.noOfRules; i++)
        {
            for(int j = 0; j < cfg.rules[i].noOfProductions; j++)
            {
                char nonTerminal = cfg.rules[i].nonTerminal;
                char *prod = removeEpsilon(cfg.rules[i].production[j]);
                if(strlen(prod) == 0)
                    continue;

                int index = getIndexInTable(table, nonTerminal, numSymbols);
                int k = 0, n = strlen(prod), forFirstX = 1;

                int xIndex = getIndexInTable(table, prod[strlen(prod)-1], numSymbols);
                changing = unionOfSets(table[xIndex].follow, table[index].follow, changing);

                char *rest = table[index].follow;
                for(int k = strlen(prod)-1; k >= 1; k--)
                {
                    int xiIndex = getIndexInTable(table, prod[k], numSymbols);
                    char *xiFirstSet = table[xiIndex].first;
                    char xi_1 = prod[k - 1];
                    int xi_1Index = getIndexInTable(table, prod[k - 1], numSymbols);
                    if(isEpsilon(xiFirstSet))
                    {
                        char *xiFirstSetWithoutEpsilon = removeEpsilon(table[xiIndex].first);
                        changing = unionOfSets(table[xi_1Index].follow, xiFirstSetWithoutEpsilon, changing);
                        changing = unionOfSets(table[xi_1Index].follow, rest, changing);
                    }
                    else
                    {
                        changing = unionOfSets(table[xi_1Index].follow, xiFirstSet, changing);
                    }
                    rest = table[xiIndex].follow;
                }
            }
        }
    }
    printFollowSets(table, numSymbols);
}

int main()
{
    FILE *fp;
    char str[MAX];
    int ruleCount = 0;

    fp = fopen("CFG.txt", "r");
    if(fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }
    while(fgets(str, MAX, fp))
    {
        ruleCount++;
        ProductionRule rule;

        rule.nonTerminal = strtok(str, " =\n")[0];
        strcpy(rule.production[0], strtok(NULL, " =\n"));
        // for inserting non terminal
        int exist = insertNonTerminal(rule.nonTerminal);
        if(!exist)
            cfg.rules[strlen(cfg.nonTerminals) - 1].nonTerminal = rule.nonTerminal;
        if(ruleCount == 1)
            cfg.startSymbol = rule.nonTerminal;
        // for inserting production
        for(int i = 0; i < strlen(cfg.nonTerminals) ; i++)
        {
            if(cfg.rules[i].nonTerminal == rule.nonTerminal)
            {
                int j = cfg.rules[i].noOfProductions;
                strcpy(cfg.rules[i].production[j], rule.production[0]);
                cfg.rules[i].noOfProductions++;
                break;
            }
        }
        // for inserting terminals
        for(int i = 0; i < strlen(rule.production[0]); i++)
        {
            if(!isupper(rule.production[0][i])) //  && rule.production[0][i] != '#'
            {
                insertTerminal(rule.production[0][i]);
            }
        }
    }
    cfg.noOfRules = ruleCount;
    printCFG();
    calculateFirstSets(cfg);
    calculateFollowSets(cfg);

    return 0;
}
