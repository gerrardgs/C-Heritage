#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode (int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
};

struct node *insertLeft (struct node *root, int value)
{
    root->left = createNode(value);
    return root->left;
};

struct node *insertRight (struct node *root, int value)
{
    root->right = createNode(value);
    return root->left;
};

void inOrderTraversal (struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d -> ", root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal (struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d -> ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal (struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal (root->left);
    postOrderTraversal (root->right);
    printf("%d -> ", root->data);
}

int main()
{
    struct node *root = createNode(1);
    insertLeft (root, 2);
    insertRight (root, 3);
    
    insertLeft (root->left, 4);
    insertRight (root->left, 5);

    printf("Inorder Traversal \n");
    inOrderTraversal(root);

    printf("\nPreorder Traversal \n");
    preOrderTraversal(root);

    printf("\nPostorder Traversal \n");
    postOrderTraversal(root);
}
