#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

int countUnservedStudents(int students[], int bubur[], int n) {
    Queue* queue = createQueue();
    int unserved = 0;

    for (int i = 0; i < n; i++) {
        enqueue(queue, students[i]);
    }

    for (int i = 0; i < n; i++) {
        int currentbubur = bubur[i];

        if (queue->front->data == currentbubur) {
            dequeue(queue);
        } else {
            enqueue(queue, queue->front->data);
            dequeue(queue);
            unserved++;
        }
    }
    return unserved;
}

int main() {
    int n;
    int o;
    printf("students = ");
    scanf("%d", &n);

    char buffer[100];
    printf("bubur = ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &o);
    getchar();

    int* students = (int*)malloc(n * sizeof(int));
    int* bubur = (int*)malloc(o * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &students[i]);
    }

    for (int i = 0; i < o; i++) {
        scanf("%d", &bubur[i]);
    }

    int unservedCount = countUnservedStudents(students, bubur, n);
    printf("\n%d", unservedCount);

    free(students);
    free(bubur);

    return 0;
}
