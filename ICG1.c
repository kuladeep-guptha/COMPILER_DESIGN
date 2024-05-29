#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, char item);
char pop(struct Stack* stack);
char peek(struct Stack* stack);
int isOperator(char ch);
int precedence(char ch);
char * infixToPostfix(char* infix);
void generateThreeAddressCode(char * postfix);

int main() {
    char infixExpression[100];
    
    printf("Enter an infix expression: ");
    scanf("%s", infixExpression);
    
    char * postfixExpression = infixToPostfix(infixExpression);

    generateThreeAddressCode(postfixExpression);

    return 0;
}

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '$'; 
}

char peek(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top];
    }
    return '$'; 
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

char* infixToPostfix(char* infix) {
    int infixLength = strlen(infix);
    int postfixLength = infixLength + 1;
    
    struct Stack* operatorStack = createStack(infixLength);
    char* postfixExpression = (char*)malloc(postfixLength * sizeof(char));

    if (!operatorStack || !postfixExpression) {
        printf("Memory error\n");
        free(operatorStack);
        free(postfixExpression);
        return NULL;
    }

    int i, j = 0;
    for (i = 0; infix[i]; i++) {
        char currentChar = infix[i];

        if (isalnum(currentChar))
            postfixExpression[j++] = currentChar;
        else if (currentChar == '(')
            push(operatorStack, currentChar);
        else if (currentChar == ')') {
            while (peek(operatorStack) != '$' && peek(operatorStack) != '(')
                postfixExpression[j++] = pop(operatorStack);
            if (peek(operatorStack) == '(')
                pop(operatorStack);
        } else {
            while (!isEmpty(operatorStack) && precedence(currentChar) <= precedence(peek(operatorStack)))
                postfixExpression[j++] = pop(operatorStack);
            push(operatorStack, currentChar);
        }
    }

    while (!isEmpty(operatorStack))
        postfixExpression[j++] = pop(operatorStack);

    postfixExpression[j] = '\0';

    free(operatorStack);

    return postfixExpression;
}

void generateThreeAddressCode(char * postfix) {
    struct Stack * operandStack = createStack(strlen(postfix));
    int tempVariableCounter = 0;

    for(int i = 0; i < strlen(postfix); i++) {
        char currentChar = postfix[i];

        if(!isOperator(currentChar)) {
            push(operandStack, currentChar);
        }
        else {
            tempVariableCounter++;
            char operand1 = pop(operandStack);
            char operand2 = pop(operandStack);

            if ((operand1>=97 && operand1<=122) && (operand2>=97 && operand2<=122)) {
                printf("t%d = %c %c %c \n", tempVariableCounter, operand2, currentChar, operand1);
            } else {
                if(operand1>=97 && operand1<=122) {
                    printf("t%d = t%c %c %c \n", tempVariableCounter, operand2, currentChar, operand1);
                }
               else if(operand2>=97 && operand2<=122) {
                    printf("t%d = %c %c t%c \n", tempVariableCounter, operand2, currentChar, operand1);
                }
                else {
                    printf("t%d = t%c %c t%c \n", tempVariableCounter, operand2, currentChar, operand1);
                }
            }

            tempVariableCounter += '0';
            push(operandStack, tempVariableCounter);
            tempVariableCounter -= '0';
        }
    }
}
