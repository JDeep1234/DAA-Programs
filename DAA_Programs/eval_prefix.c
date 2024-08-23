#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define SIZE 20

struct stack
{
    int top;
    float data[SIZE];
};

typedef struct stack STACK;

void push(STACK *s, float item)
{
    s->data[++(s->top)] = item;
}

float pop(STACK *s)
{
    return s->data[(s->top)--];
}

float operate(float opr1, float opr2, char operand)
{
    switch (operand)
    {
    case '^':
        return pow(opr1, opr2);
    case '/':
        return opr1 / opr2;
    case '*':
        return opr1 * opr2;
    case '+':
        return opr1 + opr2;
    case '-':
        return opr1 - opr2;
    }
}

float prefix_Eval(STACK *s, char prefix[SIZE])
{
    int i, len = strlen(prefix) - 1;
    float opr1, opr2, result, temp;
    char symbol;

    for (i = len; i >= 0; i--)
    {
        symbol = prefix[i];
        if (isdigit(symbol))
            push(s, symbol - 48);
        else if (isalpha(symbol))
        {
            printf("\nEnter the value of %c :", symbol);
            scanf("%f", &temp);
            printf("\n");
            push(s, temp);
        }
        else
        {
            opr1 = pop(s);
            opr2 = pop(s);
            result = operate(opr1, opr2, symbol);
            push(s, result);
        }
    }
    result = pop(s);
    return result;
}

int main()
{
    STACK s;
    s.top = -1;
    float result;
    char prefix[SIZE];
    printf("\nEnter the prefix expression : ");
    scanf("%s", prefix);
    result = prefix_Eval(&s, prefix);
    printf("\nResult is %0.3f\n", result);
    return 0;
}