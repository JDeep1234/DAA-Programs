#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define SIZE 20

// Defination of a stack as a structure

struct stack
{
    int top;
    float data[SIZE];
};
typedef struct stack STACK;

// push function

void push(STACK *s, float item)
{
    s->data[++(s->top)] = item;
}

// pop function

float pop(STACK *s)
{
    return s->data[(s->top)--];
}

// operate function performs  basic arithmetic operations

float operate(float operandOne, float operandTwo, char operation)
{
    switch (operation)
    {
    case '+':
        return operandOne + operandTwo;
    case '-':
        return operandOne - operandTwo;
    case '*':
        return operandOne * operandTwo;
    case '/':
        return operandOne / operandTwo;
    case '^':
        return pow(operandOne, operandTwo);
    }
}

// evaluates the postfix expression
/*

Input expression is a postfix expression and a pointer pointing to stack.
If the symbol read is an operand that is if it is a digit push it to the stack;
I the read symbol is an operation  then two digits are popped from the stack and placed
  onto operandTwo and operandOne respectively (because the first popped element is actually the second input and vice versa) 
  Operate function is called and result is assigned to the 'result' variable.
  the result is the pushed onto the stack for next operation.
  at last the only one element will remain in the stack that is the final result it self.
  It is then returned to the main function.


*/
float eval_postfix(STACK *s, char postfix[20])
{
    int i;
    float operandOne, operandTwo, result, temp;
    char symbol;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        symbol = postfix[i];
        if (isdigit(symbol))
            push(s, symbol - '0');
        else if(isalpha(symbol))
        {
            printf("\nEnter the value of %c",symbol);
            scanf("%f",&temp);
            printf("\n");
            push(s,temp);
        }
        else
        {
            operandTwo = pop(s);
            operandOne = pop(s);
            result = operate(operandOne, operandTwo, symbol);
            push(s, result);
        }
    }
    return pop(s);
}

int main()
{
    STACK s;
    s.top = -1;
    char postfix[20];
    float result;
    printf("\nEnter the postfix expression : ");
    scanf("%s", postfix);
    result = eval_postfix(&s, postfix);
    printf("\nThe result of %s is %0.4f.\n", postfix, result);
    return 0;
}
