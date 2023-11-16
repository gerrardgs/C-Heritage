#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(int value)
{
    struct Node* newNode = createNode(value);
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Data berhasil ditambahkan di awal\n");
}

void insertLast(int value)
{
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Data berhasil ditambahkan di akhir\n");
}

void insertAfter(int value, int key)
{
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            newNode->prev = temp;
            newNode->next = temp->next;
            if(temp->next != NULL)
            {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            printf("Data berhasil ditambahkan setelah %d\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Data %d tidak ditemukan\n", key);
}

void deleteFirst()
{
    if(head == NULL)
    {
        printf("Data kosong\n");
    }
    else
    {
        struct Node* temp = head;
        head = head->next;
        if(head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        printf("Data berhasil dihapus\n");
    }
}

void deleteLast()
{
    if(head == NULL)
    {
        printf("Data kosong\n");
    }
    else
    {
        struct Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        if(temp == head)
        {
            head = NULL;
        }
        else
        {
            temp->prev->next = NULL;
        }
        free(temp);
        printf("Data terakhir berhasil dihapus\n");
    }
}

void deleteAfter(int key)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            if(temp->next == NULL)
            {
                printf("Tidak ada value setelah data dengan nilai %d\n", key);
                return;
            }
            else
            {
                struct Node* deleteNode = temp->next;
                temp->next = deleteNode->next;
                if(deleteNode->next != NULL)
                {
                    deleteNode->next->prev = temp;
                }
                free(deleteNode);
                printf("Data %d berhasil dihapus\n", key);
                return;
            }
        }
        temp = temp->next;
    }
    printf("Data %d tidak ditemukan\n", key);
}

void searchData(int value)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            printf("Data %d ditemukan\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Data %d tidak ditemukan\n", value);
}

void displayList()
{
    struct Node* temp = head;
    if(temp == NULL)
    {
        printf("Data kosong\n");
    }
    else
    {
        printf("\n");
        while(temp != NULL)
        {
            printf("[%d] ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, value, key, deleteAfterValue;
    while(1)
    {
        printf("\nMenu Pilihan:\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert After\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete After\n");
        printf("7. Cari Data\n");
        printf("8. Exit\n");
        printf("Pilih menu yang diinginkan: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Masukkan value: ");
                scanf("%d", &value);
                insertFirst(value);
                displayList();
                break;
            case 2:
                printf("Masukkan value: ");
                scanf("%d", &value);
                insertLast(value);
                displayList();
                break;
            case 3:
                printf("Masukkan value: ");
                scanf("%d", &value);
                printf("Masukkanni value setelah data: ");
                scanf("%d", &key);
                insertAfter(value, key);
                displayList();
                break;
            case 4:
                deleteFirst();
                displayList();
                break;
            case 5:
                deleteLast();
                displayList();
                break;
            case 6:
                printf("Masukkan value data yang ingin dihapus: ");
                scanf("%d", &deleteAfterValue);
                deleteAfter(deleteAfterValue);
                displayList();
                break;
            case 7:
                printf("Masukkan value yang ingin dicari: ");
                scanf("%d", &value);
                searchData(value);
                break;
            case 8:
                printf("Terima Kasih.\n");
                exit(0);
            default:
                printf("Tidak Valid.\n");
        }
    }
    return 0;
}
