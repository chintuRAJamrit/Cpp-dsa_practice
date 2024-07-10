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
    NODE first = NULL;
    int option;
    while (1) // forgot , needed this for it to keep running until exit
    {
        printf("enter Dequeue operations\n");
        printf("1.entry restricted\n2.exit restricted\n3.display\n4.Exit\n");
        printf("enter your choice:\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("entry restricted operations\n");
            printf("1.insert from rear\n2.delete from front\n3.delete from rear\n");
            // int option;- dont need to declare again even if using again its already being declared
            printf("enter your choice:\n");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                first = insert_rear(first);
                break;
            case 2:
                first = delete_front(first);
                break;
            case 3:
                first = delete_rear(first);
                break;
            }
            break; // referred
        case 2:
            printf("exit restricted operations\n");
            printf("1.insert from front\n2.insert from rear\n3.delete from front\n");
            // int option;
            printf("enter your choice:\n");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                first = insert_front(first);
                break;
            case 2:
                first = insert_rear(first);
                break;
            case 3:
                first = delete_front(first);
                break;
            }
            break;
        case 3:             /*first =*/
            display(first); // no first =
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
    temp = (NODE)malloc(sizeof(NODE)); // refered this
    return temp;
}

NODE insert_front(NODE first) // define type of first so NODE first
{
    NODE temp;
    temp = getnode();
    printf("enter the data to insert:");
    scanf("%d", &temp->data);
    temp->link = first;
    first = temp;
    return temp;
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
    first = first->link;
    free(temp);
    return first;
}

NODE insert_rear(NODE first)
{
    NODE temp, ptr;
    temp = getnode();
    printf("enter the data to insert:");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (first == NULL)
    {
        first = temp;
        return first;
    }
    ptr = first;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp; // ptr link to the new added temp node.
    return first;
}

NODE delete_rear(NODE first)
{
    NODE prev, ptr;
    if (first == NULL)
    {
        printf("no node is present\n");
        return first;
    }
    ptr = first;
    while (ptr->link != NULL)
    {
        prev = ptr;
        ptr = ptr->link;
    }
    prev->link = NULL;
    free(ptr);
    return first;
}

void display(NODE first)
{
    NODE temp;
    // temp=getnode();- no need of this here or any delete fn bcs here temp assign some node rather than having a new node
    if (first == NULL)
    {
        printf("no node is present\n");
    }
    else // forgot this
    {
        for (temp = first; temp->link != NULL; temp = temp->link)
        {
            printf("%d=>", temp->data);
        }
        printf("%d=>", temp->data);
    }
    // no return since its voidfunction now
}
