#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int data[MAX_SIZE];
    int front, rear;
}Queue;

void initQueue(Queue *q){
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q){
    return(q->rear == MAX_SIZE -1);
}

int isEmpty(Queue *q){
    return(q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, int val){
    if(isFull(q)){
        printf("Queue Penuh!\n");
        exit(EXIT_FAILURE);
    }
    if(isEmpty(q)){
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = val;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue Kosong!\n");
        exit(EXIT_FAILURE);
    }
    int val = q->data[q->front];
    q->front++;
    return val;
}

void handlePatient(Queue *q){
    int size;
    while(!isEmpty(q)){
        size = dequeue(q);
        if(size <= 5){
            printf("ditangani dokter umum\n");
        }else{
            printf("ditangani dokter spesialis\n");
        }
    }
}

int main(){
    Queue q;
    initQueue(&q);
    int n, i, size;
    printf("Banyak Pasien: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &size);
        enqueue(&q, size);
    }
    handlePatient(&q);
    return 0;
}

//Input:
//5 1 4 8 9 7 1 2 9 4

//Output:
//ditangani dokter umum
//ditangani dokter umum
//ditangani dokter umum
//ditangani dokter spesialis
//ditangani dokter spesialis
//ditangani dokter spesialis
//ditangani dokter umum
//ditangani dokter umum
//ditangani dokter spesialis
//ditangani dokter umum
