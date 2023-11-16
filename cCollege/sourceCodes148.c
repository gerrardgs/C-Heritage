// NO. 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name;
    int distance;
    struct Node* next;
}Node;

Node* createNode(char name, int distance){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = name;
    newNode->distance = distance;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char name, int distance){
    Node* newNode = createNode(name, distance);

    if(*head == NULL){
        *head = newNode;
        (*head)->next = *head;
    }
    else{
        Node* temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

char* findTerminal(Node* head, int X, int* numRotations){
    Node* current = head;
    int totalDistance = 0;
    *numRotations = 0;

    do{
        totalDistance += current->distance;
        if(totalDistance >= X){
            break;
        }
        current = current->next;
        if(current == head){
            *numRotations += 1;
        }
    }
    while(current != head);

    char* terminalName = (char*)malloc(2 * sizeof(char));
    strncpy(terminalName, &(current->name), 1);
    terminalName[1] = '\0';
    return terminalName;
}

void freeLinkedList(Node* head){
    if(head == NULL){
        return;
    }

    Node* current = head->next;
    while(current != head){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main(){
    int X, N;
    scanf("%d %d", &X, &N);
    Node* head = NULL;

    for (int i = 0; i < N; i++){
        char terminalName;
        int distance;
        scanf(" %c %d", &terminalName, &distance);
        addNode(&head, terminalName, distance);
    }

    int numRotations;
    char* terminal = findTerminal(head, X, &numRotations);

    printf("Andi turun di stasiun %s\n", terminal);
    if(numRotations > 0){
        printf("Andi telah berputar sebanyak %d putaran\n", numRotations);
    }

    free(terminal);
    freeLinkedList(head);

    return 0;
}
