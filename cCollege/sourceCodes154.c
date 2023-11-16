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
    stack->top == -1;
}

int isEmpty (Stack *stack)
{
    return stack->top == -1;
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

void reverseStack(char *string)
{
    Stack stack;
    createStack(&stack);

    int lenght = strlen(string);

    for (int i = 0; i < lenght; i++)
    {
        push(&stack, string[i]);
    }
    printf("\n");
}

printf("Output = ");
for (int i = 0; i < lenght; i++)
{
    printf("%c", pop(&stack));
}
