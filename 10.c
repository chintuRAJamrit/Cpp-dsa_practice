#include <stdio.h>
#include <stdlib.h>


struct node
{
int data;
struct node *left;
struct node *right;
int RT;
};
typedef struct node *NODE;

NODE head=0;
NODE create(int , NODE);
void insert_left(int , NODE);
void insert_right(int , NODE);
void inorder(NODE);
NODE inorder_successor(NODE);
int ch,i,n,item;

void main()
{
    NODE head;
    head=(NODE)malloc(sizeof(struct node));
    head->right=head;
    head->left=0;//its not null , its 0
    //head->data=NULL; no need of this
    head->RT=0;
    while(1)
    {
    printf("\n1.Create tree\n2.Inorder\n3.Exit\n");
    printf("Enter the choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("enter number of node for the tree:");
                scanf("%d",&n);
                for(i=1;i<n+1;i++)
                {
                    printf("enter node %d: ",i);
                    scanf("%d",&item);
                    head=create(item,head);
                }
                break;
        case 2: inorder(head);
                break;
        case 3: exit(0);
        default: printf("invalid choice\n");
                break;
    }
    }
}


NODE create(int item, NODE head) // reffered once
{
    NODE curptr, ptr;    // remember
    if (head->left == 0) // head of left is 0 then , no use of right
    {
        insert_left(item, head);
        return (head);
    }
    curptr = head->left; // mistake
    while (curptr != head)
    {
        ptr = curptr;
        if (item < (curptr->data))
        {
            if (curptr->left != 0) /// USE 0 EVERYEHRE WITH curptr->left
                curptr = curptr->left;
            else
                break;
        }
        else
        {
            if (item > (curptr->data))
            {
                if (curptr->RT == 0)
                    curptr = curptr->right;
                else
                    break;
            }
        }
    }
    if (item < (curptr->data))
    {
        insert_left(item, ptr);
        return (head);
    }
    else
    {
        if (item > (curptr->data) && curptr->RT == 1) // remember this , it has 2 conditions
            insert_right(item, ptr);
    }
    return (head);
}

void insert_left(int item, NODE ptr)
{
    NODE temp, newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->left = 0;
    newnode->data = item;
    ptr->left = newnode;
    newnode->right = ptr;
    newnode->RT = 1;
}

void insert_right(int item, NODE ptr)
{
    NODE temp, newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->left = 0;
    newnode->data = item;
    temp = ptr->right;
    //newnode->right = temp;
    ptr->right = newnode;
    newnode->right = temp;
    ptr->RT = 0;
    newnode->RT = 1;
}

/*void inorder(NODE head)
{
    NODE temp;
    if(head->left==0)
    {
        printf("no node present:\n");
        return;//return (head); no need
    }
    //reffered
    temp=head;
    while(1)
    {
        temp=inorder_successor(temp);
        if(temp==head)
            return;
        printf("%d=>",temp->data);
    }
}

NODE inorder_successor(NODE ptr)//remember this function properly
{
    NODE temp;
    temp=ptr->right;
    if(ptr->RT==1)
        return (temp);
    while (temp->left!=0)
        temp=temp->left;
    return (temp);
}*/
void inorder(NODE head)
{
    NODE temp;
    if (head->left == 0)
    {
        printf("\n No nodes");
        return;
    }
    temp = head;
    while (1)
    {
        temp = inorder_successor(temp);
        if (temp == head)
            return;
        printf("%d=>", temp->data);
    }
}

NODE inorder_successor(NODE ptr)
{
    NODE temp;
    temp = ptr->right;
    if (ptr->RT == 1)
        return (temp);
    while (temp->left != 0)
        temp = temp->left;
    return (temp);
}
