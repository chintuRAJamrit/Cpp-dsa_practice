#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h> //remember

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE root = NULL;
NODE create_tree(char postfix[]);
float eval(NODE root);

void main()
{
    char postfix[20]; // i forgot
    float result;
    printf("enter the postfix:\n");
    scanf("%s", &postfix);       // no square bracket after postfix
    root = create_tree(postfix); // no square bracket after postfix
    result = eval(root);
    printf("result is :%f\n", result);
}

NODE create_tree(char postfix[])
{
    NODE temp;
    NODE stack[20]; // stack is also NODE
    char symbol;
    int i = 0, j = 0;
    for (i = 0; (symbol = postfix[i]) != 0; i++)
    {
        temp = (NODE)malloc(sizeof(NODE)); // inside for loop , it will be there
        temp->llink = temp->rlink = NULL;
        temp->data = symbol; // i forgot
        if (isalnum(symbol))
            stack[j++] = temp; // is equal to temp and not symbol
        else
        {
            // stack[--j]=temp->rlink;// reverse order
            temp->rlink = stack[--j];
            temp->llink = stack[--j];
            stack[j++] = temp; // important and i forgot this
        }
    }
    return stack[--j];
}

float eval(NODE root)
{
    float num;
    switch (root->data) // its root of data
    {
    case '+':
        return eval(root->llink) + eval(root->rlink); // return every where
    case '-':
        return eval(root->llink) - eval(root->rlink);
    case '*':
        return eval(root->llink) * eval(root->rlink);
    case '/':
        return eval(root->llink) / eval(root->rlink);
    case '^':
        return pow(eval(root->llink), eval(root->rlink)); // use pow for power ^
    default:
        if (isalpha(root->data))
        {
            printf("enter the number:");
            scanf("%f", &num);
            return num; // forgot this
        }
        else
            return (root->data - '0');
    }
}