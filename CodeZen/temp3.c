#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} * NODE;

NODE createBinaryTree(NODE root)
{
    printf("Enter the value of the node. \n Enter -1 for returning. \n");
    int input = 0;
    scanf(" %d", &input);
    printf("%d\n", input);
    if (input == -1 && root == NULL)
    {
        return NULL;
    }
    if (input == -1 && root != NULL)
    {
        return root;
    }
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = input;
    if (temp->data == -1)
        return NULL;
    else
    {
        printf("For left Node of %d \n", temp->data);
        temp->lchild = createBinaryTree(temp->lchild);
        printf("For right Node of %d \n", temp->data);
        temp->rchild = createBinaryTree(temp->rchild);
    }
    return temp;
}
NODE createBinarySearchTree(NODE root, int ele)
{
    NODE new_node;
    new_node = (NODE)malloc(sizeof(struct node));
    new_node->data = ele;

    if (root == NULL)
        return new_node;

    NODE curr = root;

    while (curr != NULL)
    {
        printf("%d\n", curr->data);
        if (ele < curr->data)
        {
            if (curr->lchild == NULL)
            {
                printf("inserted %d as left child of %d\n", ele, curr->data);
                curr->lchild = new_node;
                return root;
            }
            curr = curr->lchild;
        }
        else if (ele > curr->data)
        {
            if (curr->rchild == NULL)
            {
                printf("inserted %d as right child child of %d\n", ele, curr->data);
                curr->rchild = new_node;
                return root;
            }
            curr = curr->rchild;
        }
    }
    return root;
}

void inorder(NODE ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        printf("%5d", ptr->data);
        inorder(ptr->rchild);
    }
}

void postorder(NODE ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%5d", ptr->data);
    }
}

void preorder(NODE ptr)
{
    if (ptr != NULL)
    {
        printf("%5d", ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

int main()
{
    NODE root = NULL;

    printf("Enter 0.createBinaryTree \n");
    printf("Enter 1.createBinarySearchTree \n");
    printf("Enter 2.displayTree \n");
    printf("Enter 3.searchTree \n");

    int choice;
    printf("Enter your choice\n");
    scanf(" %d", &choice);

    int tempvalue;

    while (1)
    {
        switch (choice)
        {
        case 0:
            root = createBinaryTree(root);
            printf("Done\n");
            return 0;

        case 1:
            printf("Enter Root Node\n");
            scanf(" %d", &tempvalue);
            while (tempvalue != -1)
            {
                root = createBinarySearchTree(root, tempvalue);
                printf("Enter Next Node.\n Enter -1 to exit\n");
                scanf(" %d", &tempvalue);
            }
            // break;
            return 0;

        case 2:
            printf("\n Inorder Traversals \n");
            inorder(root);
            printf("\n Postorder Traversals \n");
            postorder(root);
            printf("\n Preorder Traversals \n");
            preorder(root);
            printf("\n ********* \n");
            return 0;
        case 4:
            exit(0);
        }
    }
    return 0;
}