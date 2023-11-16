#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct Stack
{
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

void createStack (Stack *stack)
{
    stack->top = -1;
}

int isEmpty (Stack *stack)
{
    return stack->top == -1;
}

int isFull (Stack *stack)
{
    return stack->top == MAX_STACK_SIZE - 1;
}

char peek (Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

void push (Stack *stack, char value)
{
    if(isFull(stack))
    {
        printf("Stack Penuh\n");
        return;
    }
    stack->top++;
    stack->data [stack->top] = value;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Kosong\n");
        return -1;
    }
    char value = stack->data[stack->top];
    stack->top--;
    return value;
}

void reverseString(char *string)
{
    Stack stack;
    createStack(&stack);

    int length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        push(&stack, string[i]);
    }

    printf("Output = ");
    for (int i = 0; i < length; i++)
    {
        printf("%c", pop(&stack));
    }
    printf("\n");
}

int main()
{
    char input[MAX_STACK_SIZE];
    printf("Input = ");
    scanf("%s", input);
    reverseString(input);
    return 0;
}
