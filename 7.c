#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node *NODE;

NODE root = NULL; // rembember
void create(NODE);
int is_lchild(NODE);
int is_rchild(NODE);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
NODE getnode(); // forgot this,

void main() // no need of wrting NODE root inside bracket bcs its globally defined
{
    printf("tree traversing\n");
    printf("enter the data for root: ");
    root = getnode();
    scanf("%d", &root->data);
    // reviewed from here
    create(root);
    printf("\ninorder traversing\n");
    inorder(root);
    printf("\npreorder traversing\n");
    preorder(root);
    printf("\npostorder traversing\n");
    postorder(root);
}

NODE getnode() // rember this
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->lchild = temp->rchild = NULL;
    return temp;
}

void create(NODE root)
{
    if (is_lchild(root))
    {
        root->lchild = getnode(); // remember this
        printf("enter the data: ");
        scanf("%d", &root->lchild->data);
        create(root->lchild); // remmber this
    }
    if (is_rchild(root))
    {
        root->rchild = getnode();
        printf("enter the data: ");
        scanf("%d", &root->rchild->data);
        create(root->rchild);
    }
}

int is_lchild(NODE root)
{
    int ch;
    printf("do you want lchild to %d? yes-1 ,no-0 ", root->data);
    scanf("%d", &ch);
    if (ch)
        return 1;
    else
        return 0;
}

int is_rchild(NODE root)
{
    int ch;
    printf("do you want rchild to %d? yes-1 ,no-0 ", root->data);
    scanf("%d", &ch);
    if (ch)
        return 1;
    else
        return 0;
}

void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}