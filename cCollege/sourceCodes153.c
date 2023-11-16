#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// struct untuk merepresentasikan stack
struct Stack {
    char data[MAX_SIZE];
    int top;
};

// fungsi untuk inisialisasi stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// fungsi untuk mengecek apakah stack kosong
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// fungsi untuk mengecek apakah stack penuh
int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// fungsi untuk menambahkan elemen ke dalam stack
void push(struct Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = c;
}

// fungsi untuk menghapus elemen dari stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

// fungsi untuk membalikkan string menggunakan stack
char* reverseString(char *str) {
    struct Stack s;
    initStack(&s);
    int i, len = strlen(str);

    // push setiap karakter ke dalam stack
    for (i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    // pop setiap karakter dari stack untuk membentuk string yang terbalik
    for (i = 0; i < len; i++) {
        str[i] = pop(&s);
    }

    return str;
}

int main() {
    char str[MAX_SIZE];
    printf("Masukkan sebuah string: ");
    scanf("%[^\n]", str);
    printf("String yang telah dibalikkan: %s\n", reverseString(str));
    return 0;
}
