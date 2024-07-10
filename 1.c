//stack implentation using array

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 3

int stack[SIZE];

int push(int);
int pop(int);
void display(int);

int main()
{
    int top = -1;
    int option;
    // clrscr();
    while (1)
    {

        printf("Stack operation:\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("enter the choice:\n");
        scanf("%d", &option);
        switch(option)
        {
        case 1: top = push(top); // top alreeady declared , so no need for "int top" by giving parameter
            //getch();
            break;
        case 2: top = pop(top); // top= used because return is  new top that is being assigned here
            //getch();
            break;
        case 3: display(top);//using return type bcs top defind inside main
            //getch();
            break;
        case 4: exit(0);

        default: printf("Invalid Choice\n");
        }
    }
    return 0;
}

int push(int top)//if no reutrn type mentioned means its int
{
     int x;
    if (top == (SIZE - 1))
    {
        printf("stack is full\n");
        return top;
    }
    else
    {
       
        printf("enter the number to push\n");
        scanf("%d", &x);
        stack[++top] = x;
        printf("succesfully pushed\n");
        return top;
    }
}

int pop(int top)
{
    if (top == -1)
    {
        printf("stack is empty\n");
        return ;
    }
    else
    {

        printf("succesfully popped out\n");
        top--;
        return top;
    }
}

void display(int top)
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--) // stack is LIFO so will be the pritning order.
        {
            printf("%d\n", stack[i]);
        }
    }
}
