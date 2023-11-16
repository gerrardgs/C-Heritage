#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct Stack
{
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void createStack (Stack *stack)
{
    stack->top = -1;
}

int isEmpty (Stack *stack)
{
    return stack->top = -1;
}

int isFull (Stack *stack)
{
    return stack->top = MAX_STACK_SIZE - 1;
}

int peek (Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

void push (Stack *stack, int value)
{
    if(isFull(stack))
    {
        printf("Stack Penuh\n");
        return;
    }
    stack->top++;
    stack->data [stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Kosong\n");
        return -1;
    }
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

void printStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("\nStack Kosong");
        return;
    }
    printf("\nStack: ");
    for (int  i = stack->top; i>= 0; i--)
    {
        printf ("%d ", stack->data[i]);  
    }
    
}

int main() {
   Stack varStack;
    createStack(&varStack);
    int choice, value;
    while (1) {
        printStack(&varStack);
        printf("\nMenu Stack\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Keluar\n");
        printf("Pilihan anda: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Masukkan nilai yang akan ditambahkan: ");
                scanf("%d", &value);
                push(&varStack,value);
                break;
            case 2:
                printf("Elemen yang dihapus adalah %d\n", pop(&varStack));
                break;
            case 3:
                printf("Elemen Top adalah %d\n", peek(&varStack));
                break;
            case 4:
                printf("Terima kasih!\n");
                return 0;
            default:
                printf("Error: Pilihan tidak valid!\n");
        }
    }
}
