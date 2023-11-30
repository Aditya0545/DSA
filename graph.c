#include <stdio.h>
#include <malloc.h>
struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
} *root;
main()
{
    int choice, num;
    root = NULL;
    while (1)
    {
        printf("\n");
        printf("1. Insert");
        printf("1. Deletion");
        printf("1. Inorder Traversal\n");
        printf("1. Preorder Traversal\n");
        printf("1. Postorder Traversal\n");
        printf("1. Quit");
        printf("\nEnter Your Choice: ");
        printf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number to be inserted: ");
            scanf("%d", &num);
            insert(num);
            break;

        case 2:
            printf("Enter the number to be deleted: ");
            scanf("%d", &num);
            del(num);
            break;

        case 3:
            inorder(root);
            break;

        case 4:
            preorder(root);
            break;

        case 5:
            postorder(root);
            break;

        case 6:
            exit();

        default:
            printf("Wrong Choice\n");
        } /*End of Switch*/
    }     /*End of While*/
} /*End of main*/

find(int item, struct node **par, struct node **loc)
{
    struct node *ptr, *ptrsave;
    if (root == NULL) /*Tree emply*/
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info) /*item is at root*/
    {
        *loc = root;
        *par = NULL;
        return;
    }
    /*Initialize ptr end ptrsave*/
    if (item < root->info)
        ptr = root->lchild;
    else
        ptr = root->rchild;
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }            /*End of While*/
    *loc = NULL; /*item not Found*/
    *par = ptrsave;
} /*End of Find*/

insert(int item)
{
    struct node *tmp, *parent, *location;
    find(item, &parent, &location);
    if (location != NULL)
    {
        printf("Item already present");
        return;
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = item;
    tmp->lchild = NULL;
    tmp->rchild = NULL;

    if (parent == NULL)
        root = tmp;
    else if (item < parent->info)
        parent->lchild = tmp;
    else
        parent->rchild = tmp;
} /*End of insert()*/
del(int item)
{
    struct node *parent, *location;
    if (root == NULL)
    {
        printf("Three Empty");
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        printf("Item not present in tree");
        return;
    }
    if (location->lchild == NULL && location->rchild == NULL)
        case_a(parent, location);
    if (location->lchild != NULL && location->rchild == NULL)
        case_b(parent, location);
    if (location->lchild == NULL && location->rchild != NULL)
        case_b(parent, location);
    if (location->lchild != NULL && location->rchild != NULL)
        case_c(parent, location);
    free(location);
} /*End of del*/

case_a(struct node *par, struct node *loc)
{
    if (par == NULL) /*item to be deleted is root node*/
        root == NULL;
    else if (loc == par->lchild)
        par->lchild = NULL;
    else
        par->lchild = NULL;
} /*End of case_a()*/

case_b(struct node *par, struct node *loc)
{
    struct node *child;
    /*Initialize child*/
    if (loc->lchild != NULL) /*item to be deleted has lchild*/
        child = loc->lchild;
    /*item to be deleted has rchild*/
    child = loc->rchild;
    if (par == NULL) /*item to be deleted is root node*/
        root = child;
    else if (loc = par->lchild) /*item is lchild of its parent*/
        par->lchild = child;
    /*item is rchild of its parent*/
    else
        par->rchild = child;
} /*End of Case_b()*/

case_c(struct node *par, struct node *loc)
{
    struct node *ptr, *ptrsave, *suc, *parsuc;
    /*Find Inorder successor and its parent*/
    ptrsave = loc;
    ptr = loc->rchild;
    while (ptr->lchild != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->lchild;
    }
    suc = ptr;
    parsuc = ptrsave;

    if (suc->lchild == NULL && suc->rchild == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL) /*if item to be deleted is root node*/
        root = suc;
    else if (loc == par->lchild)
        par->lchild = suc;
    else
        par->rchild = suc;
    suc->lchild = loc->lchild;
    suc->rchild = loc->rchild;
} /*End of case c()*/

preoder(struct node *ptr)
{
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    if (ptr != NULL)
    {
        printf("%c", ptr->info);
        preoder(ptr->lchild);
        preoder(ptr->rchild);
    }
} /*End of Preorder*/

inorder(struct node *ptr)
{
    if (root == NULL)
    {
        printf("Tree is Empty");
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        printf("%c", ptr->info);
        inorder(ptr->rchild);
    }
} /*End of inorder*/

postorder(struct node *ptr)
{
    if (root == NULL)
    {
        printf("Tree is Empty");
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%c", ptr->info);
    }
} /*End of Postorder*/