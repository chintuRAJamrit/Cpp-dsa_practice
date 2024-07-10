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
NODE insert(NODE);
NODE delete(NODE);
void inorder(NODE);

int main()
{
    NODE root;
    root = getnode();
    printf("enter the root data : ");
    scanf("%d", &root->data);
    int option;
    while (1)
    {
        printf("tree operation: \n");
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        scanf("%d", &option); // all this inside while loop
        switch (option)
        {
        case 1:
            root = insert(root);
            break;
        case 2:
            root = delete (root);
            break;
        case 3:
            printf("Display\n");
            inorder(root);
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice\n");
        }
    }
}

NODE insert(NODE root)
{
    NODE temp1, temp, prev;
    int item;
    temp1 = getnode();
    printf("enter the data: ");
    scanf("%d", &temp1->data);
    item = temp1->data;
    prev = NULL;
    temp = root;
    while (temp != NULL)
    {
        prev = temp;
        if (item < temp->data)
            temp = temp->llink;
        else
            temp = temp->rlink;
    }
    if (item < prev->data)
        prev->llink = temp1;
    else
        prev->rlink = temp1;
    return root;
}
NODE getnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(NODE));
    temp->llink = temp->rlink = NULL;
    return temp;
}

NODE delete(NODE root)
{
    NODE suc, parent, cur, q; // q is node here
    int item;
    printf("enter the iteam to delete: \n");
    scanf("%d", &item);
    if (root == NULL) // remember
    {
        printf("no node present\n");
        return root;
    }
    parent = NULL; // u forgot
    cur = root;
    while (cur != NULL && item != cur->data)
    {
        parent = cur;
        if (item < cur->data)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (cur == NULL)
    {
        printf("item not found");
        return root;
    }
    if (cur->llink == NULL)
        q = cur->rlink;
    else if (cur->rlink == NULL) // remember else if condition
        q = cur->llink;
    else
    {
        suc = cur->rlink;
        while (suc->llink != NULL) // not equaal to null
            suc = suc->llink;
        suc->llink = cur->llink;
        q = cur->rlink;
    }
    if (cur == parent->llink)
        parent->llink = q; // same as condition in llink
    else
        parent->rlink = q;
    free(cur); // remember this
    return root;
}

void inorder(NODE root)
{
    if (root != NULL) // rememberr format in tree about displaying
    {
        inorder(root->llink);
        printf("%d=>", root->data);
        inorder(root->rlink);
    }
}