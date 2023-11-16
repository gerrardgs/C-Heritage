#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int value;
    struct Node *next;
}Node;

Node *createNode(){
    Node *newNode = malloc(sizeof(Node)); // newNode berupa pointer karena malloc menentukan alamat memori
    printf("Input Value: ");
    scanf("%d", &newNode->value);
    return newNode;
}

Node *InsertLast(Node *node)
{
    Node *newNode = createNode();
    if (node == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    else
    {
        node->prev->next = newNode;
        newNode->next = node;
        newNode->prev = node->prev;
        node->prev = newNode;
        return node;
    } 
}

Node *insertFirst(Node *node)
{
    node = InsertLast(node);
    node = node->prev;
    return node;
}

Node *deleteLast(Node *node)
{
    Node *tmp = node->prev;
    node->prev->prev->next = node;
    node->prev = node->prev->prev;
    free(tmp);
    return node;
}

Node *deleteFirst(Node *node)
{
    Node *tmp = node;
    node->prev->next = node->next;
    node->next->prev == node->prev;
    free(tmp);
    return node->next;
}

Node *insertAfter(Node *node, int value)
{
    Node *current = node;
    while (current->value != value)
    {
        if (current->next == node && current->value != value)
        {
            return node;
        }
        current = current->next;
    }
    Node *newNode = createNode();
    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    return node;
}

Node *deleteValue(Node *node, int value)
{
    Node *current = node;
    while (current->value != value)
    {
        if (current->next == node && current->value != value)
        {
            return node;
        }
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    return node;
}

void showData(Node *node)
{
    if (node == NULL)
    {
        printf("[]\n");
    }
    else
    {
        Node *current = node;
        while (current->next != node)
        {
            printf("[%d]", current->value);
            current = current->next;
        }
        printf("[%d]\n", current->value);
    }
}

int main()
{
    Node *head = NULL;
    int choice;
    do
    {
        printf("Menu : \n");
        printf("1. Insert Node\n");
        printf("2. Insert First\n");
        printf("3. Delete First\n");
        printf("4. Delete Last\n");
        printf("5. Insert After\n");
        printf("6. Delete Value\n");
        printf("CHOSEN: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            system("cls");
            head = createNode(head);
        }
        else if (choice == 2)
        {
            system("cls");
            head = insertFirst(head);
        }
        else if (choice == 3)
        {
            system("cls");
            head = deleteFirst(head);
        }
        else if (choice == 4)
        {
            system("cls");
            head = deleteLast(head);
        } 
        else if (choice == 5)
        {
            int value;
            printf("Find Value: ");
            scanf("%d", &value);
            head = insertAfter(head, value);
        }
        else if (choice == 6)
        {
            int value;
            printf("Find Value: ");
            scanf("%d", &value);
            head = deleteValue(head, value);
        }
    }
    while(1);
    return 0;
}
