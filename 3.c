#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sym, infix[20], post[20], stack[20];
int top = -1, len, j, i; // see all objects defined and created
void infixtopost();
int preceed(char);
void main()
{
    int h = 0;
    printf("enter the infix expression: ");
    scanf("%s", &infix); //%s hoga
    len = strlen(infix) - 1;
    for (int h = 0; h < len / 2; h++)
    {
        char temp = infix[h];
        infix[h] = infix[len - h];
        infix[len - h] = temp;
    }
    for (int i = 0; i <= len; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    infixtopost();
    printf("prefix expression is-\n");
    for (int i = strlen(post) - 1; i >= 0; i--) // see initailization
    {
        printf("%c", post[i]);
    }
    printf("\n");
}
int pop()
{
    char temp;
    temp = stack[top--];
    return temp;
}
void push(char sym)
{
    stack[++top] = sym;
}

void infixtopost() // refer once again here
{
    char temp;
    len = strlen(infix);
    push('#');      // # in inverted comma
    while (i < len) // cant declare int i inside while loop
    {
        sym = infix[i];
        switch (sym)
        {
        case '(':
            push(sym);
            break;
        case ')':
            temp = pop();
            while (temp != '(') // rembember this block
            {
                post[j++] = temp;
                temp = pop();
            }
            break;
        case '^':
        case '/':
        case '*':
        case '+':
        case '-':
            while (preceed(stack[top]) == preceed(sym)) // this code block refered
            {                                           // here refer object passed wit while loop
                temp = pop();
                post[j++] = temp; // j++ forgot
            }
            push(sym);
            break;
        default:
            post[j++] = sym;
        }
        i++;
    }
    while (top > 0) // forgot this block completely
    {
        post[j++] = pop();
    }
}

int preceed(char sym) // remember object passed
{
    int p;
    switch (sym)
    {
    case '^':
        p = 3;
        break;
    case '/':
    case '*':
        p = 2;
        break;
    case '+':
    case '-':
        p = 1;
        break;
    case '(':
    case ')':
        p = 0;
        break;
    case '#':
        p = -1;
        break;
    }
    return (p); // p in bracket
}
