#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 15

struct stack // Structure to create a stack later.
{
    char data[SIZE];
    int top;
};
typedef struct stack STACK;

void push(STACK *s, char item)
{
    s->data[++(s->top)] = item;
}

char pop(STACK *s)
{
    return s->data[(s->top)--];
}

int precedence(char item)
{
    switch (item)
    {
    case '^':
        return 3;

    case '*':
    case '/':
        return 2;

    case '+':
    case '-':
        return 1;
    }
}

/*char reverse(char array[])
{
    int len = strlen(array), i, count = 0;
    char reversed[len];
    for (i = 0; i < len; i++)
    {
        reversed[i] = array[len - i - 1];
        count++;
    }
}*/

void infix_to_prefix(STACK *s, char infix_exp[15])
{
    int len = strlen(infix_exp), i;
    int j = len;
    char symbol, prefix_exp[15], temp;
    for (i = len; i >= 0; i--)
    {
        symbol = infix_exp[i];
        if (isalnum(symbol))
            prefix_exp[j--] = symbol;
        else
        {
            if (symbol == ')')
                symbol = '(';
            if (symbol == '(')
                symbol = ')';

            switch (symbol)
            {
            case '(':
                push(s, symbol);
                break;
            case ')':
                temp = pop(s);
                while

                default:
                    break;
            }
        }
    }
}