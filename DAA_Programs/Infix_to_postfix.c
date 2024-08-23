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

void infix_to_postfix(STACK *s, char infix_exp[15])
// ------------------------------------------------------------------------------------------------------------------
/*Agorithm for a function C to convert Infix expression to postfix expression*/
/*   Step 1 - Scan the given infx expression from left to right
     Step 2 - if the scanned symbol is i) Operand - place it on the post fix expression. ii) left parenthesis - push it onto stack.
              iii) right parenthesis - pop the content of the stack until the corresponding left parenthesis is found in stack
              iv) operator - if: stack is empty or top of the stack is a left parenthesis - push the operator onto the stack
                            else: while stack has a higher or equal precedence operator than scanned symnol and stack is not empty and top of stack is not a left parenthesis pop the content of stack and place it on the postfix expression.
                            push the operator onto stack
    Step 3 - Until the stack becomes empty , pop the contents of the stack and place them on the postfix expression.*/
// ------------------------------------------------------------------------------------------------------------------
{
    int i, j = 0;
    char symbol, postfix_exp[15], temp;
    for (i = 0; infix_exp[i] != '\0'; i++)
    {
        symbol = infix_exp[i];
        if (isalnum(symbol))
        {
            postfix_exp[j++] = symbol;
        }

        else
        {
            switch (symbol)
            {
            case '(':
                push(s, symbol);
                break;
            case ')':
                temp = pop(s);
                while (temp != '(')
                {
                    postfix_exp[j++] = temp;
                    temp = pop(s);
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if (s->top == -1 || s->data[s->top] == '(')
                {
                    push(s, symbol);
                }

                else
                {
                    while ((precedence(s->data[s->top]) >= precedence(symbol)) && (s->top != -1) && (s->data[s->top] != '('))
                    {
                        postfix_exp[j++] = pop(s);
                    }
                    push(s, symbol);
                }

                break;
            }
        }
    }
    while (s->top != -1)
    {
        postfix_exp[j++] = pop(s);
    }
    postfix_exp[j] = '\0';
    printf("\nPostfix expression is %s\n", postfix_exp);
}

int main()
{
    STACK s;
    s.top = -1;
    char infix_exp[SIZE];
    printf("\nRead the infix expression\n");
    scanf("%s", infix_exp);
    infix_to_postfix(&s, infix_exp);
    return 0;
}