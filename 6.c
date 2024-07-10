#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;

NODE getnode();
NODE insert_pos(NODE);
NODE delete_front(NODE);
NODE insert_rear(NODE);
NODE delete_pos(NODE);
void display(NODE);

void main()
{
    NODE first = NULL;
    // first->llink = first->rlink = NULL; // wasnt there// no use here else segmentation error
    int option;
    while (1)
    {
        printf("double linked list operations\n");
        printf("1.insert\n2.Delete\n3.display\n4.Exit\n");
        printf("enter your choice:\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("insert operation\n");
            printf("1.insert position\n2.insert rear\n");
            printf("enter your choice:\n");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                first = insert_pos(first);
                break;
            case 2:
                first = insert_rear(first);
                break;
            }
            break; // referred
        case 2:
            first = delete_pos(first);
            break;
        case 3:
            display(first);
            break;
        case 4:
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
    // temp->llink = temp->rlink = NULL; // wasnt there
    return temp;
}

NODE insert_pos(NODE first)
{
    NODE temp, ptr;
    int count, pos;
    temp = getnode();
    temp->llink = temp->rlink = NULL;
    if (first == NULL)
    {
        printf("enter the data to insert:");
        scanf("%d", &temp->data);
        first = temp;
        return first;
    }
    count = 1;
    ptr = first;
    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
        count++;
    }
    printf("enter the postion to insert\n");
    scanf("%d", &pos);
    if (pos > count)
    {
        printf("invalid position\n");
        return first;
    }
    // from here
    printf("enter the data to insert:");
    scanf("%d", &temp->data);
    if (pos == 1)
    {
        temp->rlink = first;
        first->llink = temp;
        first = temp;
        return first;
    }
    // till here , u forgot . remember***
    count = 1;
    ptr = first;
    while (count < pos)
    {
        ptr = ptr->rlink;
        count++;
    }

    ptr->llink->rlink = temp;
    temp->llink = ptr->llink;
    temp->rlink = ptr;
    ptr->llink = temp; // forgot this
    printf("%d successfully inserted : ", temp->data);
    return first;
}

NODE delete_pos(NODE first)
{
    NODE ptr; // no temp
    int pos, count;
    if (first == NULL)
    {
        printf("no node is present\n");
        return first;
    }

    count = 1;
    ptr = first;
    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
        count++;
    }
    printf("enter the postion to insert\n");
    scanf("%d", &pos);
    if (pos > count)
    {
        printf("invalid position\n");
        return first;
    }
    if (pos == 1) // forgot rhis
    {
        first = delete_front(first);
        return first;
    }
    count = 1;
    ptr = first;
    while (count < pos)
    {
        ptr = ptr->rlink;
        count++;
    }
    ptr->llink->rlink = ptr->rlink;
    ptr->rlink->llink = ptr->llink; // review this
    free(ptr);
    return first;
}

NODE insert_rear(NODE first)
{
    NODE temp, ptr;
    temp = getnode();
    temp->llink = temp->rlink = NULL;
    printf("enter the data to insert:");
    scanf("%d", &temp->data);
    if (first == NULL)
    {
        first = temp;
        return first;
    }
    ptr = first;
    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
    }
    ptr->rlink = temp;
    temp->llink = ptr;
    return first;
}

NODE delete_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("no node is present\n");
        return first;
    }
    temp = first;
    temp->rlink->llink = NULL;
    first = temp->rlink;
    free(temp);
    return first;
}

void display(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("no node is present\n");
    }
    else
    {
        for (temp = first; temp->rlink != NULL; temp = temp->rlink)
        {
            printf("%d=>", temp->data);
        }
        printf("%d=>", temp->data);
    }
}
