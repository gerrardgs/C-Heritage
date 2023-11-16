#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int value;
    struct Node *next;
    
} Node;

Node *CreateNode()
{
    Node *newNode = malloc(sizeof(Node));
    printf("Insert Value: ");
    scanf("%d", &(newNode->value));
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void show(Node *node)
{
    if (node == NULL)
    {
        printf("[ ]\n");
    }
    else
    {
        while (node->next != NULL)
        {
            printf("%d", node->value);
            node = node->next;
        }
        printf("[%d]\n", node->value);
    }
}

Node *InsertNode(Node *node)
{
    Node *newNode = CreateNode();
    if (node == NULL)
    {
        node = newNode;
    }
    else
    {
        Node *tmp = node;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->prev = tmp;
    }
    return node;
}

void showDescending(Node *node)
{
    if (node != NULL)
    {
        while (node->next != NULL)
        {
            node = node->next;
        }
        while (node->prev != NULL)
        {
            printf("[%d] ", node->value);
            node = node->prev;
        }
        printf("[%d] ", node->value);
    }
    else printf("[ ]\n");
    // system("pause");
}

Node *insertBefore(Node *node)
{
    int findValue;
    printf("Value inserted before: ");
    scanf("%d", &findValue);
    Node *tmp = node;
    while(tmp->value != findValue && tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    if (tmp->value == findValue)
    {
        Node *newNode = CreateNode();
        tmp->prev->next = newNode;
        newNode->prev = tmp->prev;
        tmp->prev = newNode;
        newNode->next = tmp;
        return node;
    }
    else
    {
        printf("Value Not Found");
        // system("pause");
        return node;
    }
}

Node *deleteNode(Node *node)
{
    int findValue;
    printf("Value inserted before: ");
    scanf("%d", &findValue);
    Node *tmp = node;
    while(tmp->value != findValue && tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    if(tmp->value == findValue)
    {
        if(tmp->prev == node)
        {
            Node *tmp = node;
            node = tmp->next;
            free(tmp);
            return node;
        }
        else if(tmp == node)
        {
            printf("Can't delete the null's value");
            // system("pause");
            return node;
        }
        else
        {
            tmp->prev->prev->next = tmp;
            tmp->prev = tmp->prev->prev;
            return node;
        }
    }
}

int main()
{
    Node *head = NULL;
    int choice;
    do
    {
        (choice == NULL || choice != 2) ? show(head) : printf("\n");
        printf("Menu : \n");
        printf("1. Insert Node\n");
        printf("2. Show Descending\n");
        printf("3. Insert Before\n");
        printf("4. Delete Before\n");
        printf("0. Exit\n");
        printf("Masukkan Pilihan : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            system("cls");
            head = InsertNode(head);
        }
        else if (choice == 2)
        {
            system("cls");
            showDescending(head);
        }
        else if (choice == 3)
        {
            system("cls");
            insertBefore(head);
        }
        else if (choice == 4)
        {
            system("cls");
            deleteNode(head);
        }
    }
    while (choice != 0);
}
