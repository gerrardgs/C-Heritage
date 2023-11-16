#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    int key;
    int priority;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int key){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->priority = rand()%100;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* rotateRight(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;
    return x;
}

Node* rotateLeft(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;
    return y;
}

Node* insert(Node* root, int key){
    if(root == NULL){
        return createNode(key);
    }
    if(key < root->key){
        root->left = insert(root->left, key);
        if(root->left->priority > root->priority){
            root = rotateRight(root);
        }
    }
    else if(key > root->key){
        root->right = insert(root->right, key);
        if(root->right->priority > root->priority){
            root = rotateLeft(root);
        }
    }
    return root;
}

Node* search(Node* root, int key){
    if(root == NULL || root->key == key){
        return root;
    }
    if(key < root->key){
        return search(root->left, key);
    }
    return search(root->right, key);
}

Node* deleteNode(Node* root, int key){
    if(root == NULL){
        return root;
    }
    if(key < root->key){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->key){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            root = temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            root = temp;
        }
        else if(root->left->priority < root->right->priority){
            root = rotateLeft(root);
            root->left = deleteNode(root->left, key);
        }
        else{
            root = rotateRight(root);
            root->right = deleteNode(root->right, key);
        }
    }
    return root;
}

void inorderTraversal(Node* root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main(){
    srand(time(0));

    Node* root = NULL;
    int choice, key;

    while(1){
        printf("\nTreap Menu\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("\n");
                printf("Key %d inserted.\n", key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if(search(root, key) != NULL){
                    printf("\n");
                    printf("Key %d found in the treap.\n", key);
                }
                else{
                    printf("\n");
                    printf("Key %d not found in the treap.\n", key);
                }
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("\n");
                printf("Key %d deleted.\n", key);
                break;
            case 4:
                printf("\n");
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("\n");
                printf("Invalid choice! Please enter a valid menu number.\n");
        }
    }
    return 0;
}
