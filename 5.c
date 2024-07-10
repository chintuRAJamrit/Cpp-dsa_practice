#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node *NODE;

NODE getnode();
NODE insert_front(NODE);
NODE delete_front(NODE);
NODE insert_rear(NODE);
NODE delete_rear(NODE);
void display(NODE); // dispaly is void

void main()
{
    NODE head;
    int option;
    head = getnode();
    head->link = head;
    while (1)
    {
        printf("circular linked list operation\n");
        printf("1.inssert front\n2.insert rear\n3.delete front\n4.delete rear\n5.display\n6.Exit\n");
        printf("enter your choice:\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            head = insert_front(head);
            break;
        case 2:
            head = insert_rear(head);
            break;
        case 3:
            head = delete_front(head);
            break;
        case 4:
            head = delete_rear(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(0);
        default:
            printf("invalid choice\n");
        }
    }
}

NODE getnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(NODE));
    return temp;
}

NODE insert_front(NODE head) // define type of first so NODE first
{
    NODE temp;
    temp = getnode();
    printf("enter the data to insert:");
    scanf("%d", &temp->data);
    temp->link = head->link; // remember, it was confusing
    head->link = temp;       // same confusing , see which is LHS andd RHS
    return head;
}

NODE delete_front(NODE head)
{
    NODE temp;
    if (head->link == head)
    {
        printf("no node is present\n");
        return head;
    }
    temp = head->link;
    head->link = temp->link;
    free(temp);
    return head;
}

NODE insert_rear(NODE head)
{
    NODE temp, ptr;
    temp = getnode();
    printf("enter the data to insert:");
    scanf("%d", &temp->data);
    ptr = head->link;
    // while loop, not for loop
    while (ptr->link != head)
        ptr = ptr->link;
    ptr->link = temp;
    temp->link = head;
    return head;
}

NODE delete_rear(NODE head)
{
    NODE prev, ptr;
    if (head->link == head)
    {
        printf("no node is present\n");
        return head;
    }
    ptr = head->link;
    while (ptr->link != head)
    {
        prev = ptr;
        ptr = ptr->link;
    }
    prev->link = head;
    free(ptr);
    return head;
}

void display(NODE head)
{
    NODE temp;

    if (head->link == head)
    {
        printf("no node is present\n");
    }
    else
    {
        for (temp = head->link; temp->link != head; temp = temp->link)
        {
            printf("%d=>", temp->data);
        }
        printf("%d", temp->data);
    }
}
