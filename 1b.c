// queue implentation using array

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 3

int queue[SIZE];
int front = -1;
int rear = -1;

void insert();
void delete();
void display();

int main()
{

    int option;
    // clrscr();
    while (1)
    {

        printf("queue operation:\n");
        printf("1.insert\n2.delete\n3.Display\n4.Exit\n");
        printf("enter the choice:\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert(); // top alreeady declared , so no need for "int top" by giving parameter
            // getch();
            break;
        case 2:
            delete (); // top= used because return is  new top that is being assigned here
            // getch();
            break;
        case 3:
            display(); // using return type bcs top defind inside main
            // getch();
            break;
        case 4:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}

void insert() // if no return type mentioned means its int
{
    int n;
    if (rear == SIZE - 1)
    {
        printf("queue is full\n");
    }
    printf("enter number to insert\n");
    scanf("%d", &n);
    queue[++rear] = n;
    printf("%d insert successfully\n", n);
    if (front == -1)
    {
        front++;
    }
}

void delete() // see logic
{
    if (front == -1)
    {
        printf("queue is Empty\n");
    }
    if (front == rear)
    {
        printf("%d deleted element\n", queue[front]);
        front = -1;
        rear = -1;
    }
    printf("%d deleted element\n", queue[front]);
    front++;
}

void display()
{
    if (front == -1)
    {
        printf("queue is empty\n");
    }

    printf(" queue overview\n");
    for (int i = front; i <= rear; i++) // stack is LIFO so will be the pritning order.
    {
        printf("%d\n", queue[i]);
    }

    printf("\n");
}
