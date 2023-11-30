#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *lchild;
    struct node *rchild;
} *root;

// Function declarations
void insert(int item);
void del(int item);
void case_a(struct node *par, struct node *loc);
void case_b(struct node *par, struct node *loc);
void case_c(struct node *par, struct node *loc);
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
void exit_program();

// Function to find a node in the tree
void find(int item, struct node **par, struct node **loc) {
    struct node *ptr, *ptrsave;
    if (root == NULL) {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info) {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->info)
        ptr = root->lchild;
    else
        ptr = root->rchild;
    ptrsave = root;
    while (ptr != NULL) {
        if (item == ptr->info) {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }
    *loc = NULL;
    *par = ptrsave;
}

// Function to insert a node into the tree
void insert(int item) {
    struct node *tmp, *parent, *location;
    find(item, &parent, &location);
    if (location != NULL) {
        printf("Item already present\n");
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
}

// Function to delete a node from the tree
void del(int item) {
    struct node *parent, *location;
    if (root == NULL) {
        printf("Tree Empty\n");
        return;
    }
    find(item, &parent, &location);
    if (location == NULL) {
        printf("Item not present in tree\n");
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
}

// Function for case_a
void case_a(struct node *par, struct node *loc) {
    if (par == NULL)
        root = NULL;
    else if (loc == par->lchild)
        par->lchild = NULL;
    else
        par->rchild = NULL;
}

// Function for case_b
void case_b(struct node *par, struct node *loc) {
    struct node *child;
    if (loc->lchild != NULL)
        child = loc->lchild;
    else
        child = loc->rchild;
    if (par == NULL)
        root = child;
    else if (loc == par->lchild)
        par->lchild = child;
    else
        par->rchild = child;
}

// Function for case_c
void case_c(struct node *par, struct node *loc) {
    struct node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->rchild;
    while (ptr->lchild != NULL) {
        ptrsave = ptr;
        ptr = ptr->lchild;
    }
    suc = ptr;
    parsuc = ptrsave;

    if (suc->lchild == NULL && suc->rchild == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
        root = suc;
    else if (loc == par->lchild)
        par->lchild = suc;
    else
        par->rchild = suc;
    suc->lchild = loc->lchild;
    suc->rchild = loc->rchild;
}

// Function for preorder traversal
void preorder(struct node *ptr) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    if (ptr != NULL) {
        printf("%d ", ptr->info);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

// Function for inorder traversal
void inorder(struct node *ptr) {
    if (root == NULL) {
        printf("Tree is Empty\n");
        return;
    }
    if (ptr != NULL) {
        inorder(ptr->lchild);
        printf("%d ", ptr->info);
        inorder(ptr->rchild);
    }
}

// Function for postorder traversal
void postorder(struct node *ptr) {
    if (root == NULL) {
        printf("Tree is Empty\n");
        return;
    }
    if (ptr != NULL) {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d ", ptr->info);
    }
}

// Function to exit the program
void exit_program() {
    exit(0);
}

int main() {
    int choice, num;
    root = NULL;

    while (1) {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Deletion\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Quit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                exit_program();
                break;

            default:
                printf("Wrong Choice\n");
        } /*End of Switch*/
    }     /*End of While*/

    return 0;
} /*End of main*/
