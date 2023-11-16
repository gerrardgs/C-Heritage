// NO. 3

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100 // mendeclare maks dari ukuran stack

typedef struct{ // mendeclare tipe data stack
    char notasi[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, char a){// mendeclare fungsi untuk menambahkan elemen pada stack
    if (stack->top == MAX_SIZE - 1){ // mendeclare suatu kondisi jika stack sudah penuh, maka program akan menampilkan output berupa "Stack Penuh"
        printf("Stack penuh\n");
        exit(1);
    }
    stack->top++;// mendeclare variabel untuk menambahkan elemen pada stack
    stack->notasi[stack->top] = a;
}

char pop(Stack *stack){ // mendeclare sebuah fungsi untuk menghapus elemen pada stack
    if (stack->top == -1){// mendeclare suatu kondisi jika stack kosong, maka program akan menampilkan output berupa "Stack kosong"
        printf("Stack kosong\n");
        exit(1);
    }
    char c = stack->notasi[stack->top]; // dan mengambil elemen teratas pada stack
    stack->top--;
    return c;
}

int isOperator(char a){ // mendeclare sebuah fungsi sebagai pengecek apakah karakter merupakan operator
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^'){
        return 1;
    } else{
        return 0;
    }
}

int getPrecedence(char a){ // mendeclare sebuah kondisi untuk mendapatkan nilai prioritas dari operator
    if (a == '^'){
        return 3;
    } else if (a == '*' || a == '/'){
        return 2;
    } else if (a == '+' || a == '-'){
        return 1;
    } else{
        return 0;
    }
}

void infixToPostfix(char *infix, char *postfix){// mendeclare suatu fungsi untuk mengubah ekspresi pada infix ke positif
    Stack stack;
    stack.top = -1;
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++){
        if (isalnum(infix[i])){// mendeclare suatu kondisi jika karakter merupakan huruf atau angka
            postfix[j] = infix[i];
            j++;
        } else if (infix[i] == '('){// mendeclare suatu kondisi jika karakter merupakan tanda kurung buka, maka program akan mempush karakter tersebut ke stack
            push(&stack, infix[i]);
        } else if (infix[i] == ')'){// mendeclare suatu kondisi jika karakter merupakan tanda kurung tutup, maka program akan mempop elemen di stack sampai menemukan tanda kurung buka
            while (stack.notasi[stack.top] != '('){
                postfix[j] = pop(&stack);
                j++;
            }
            pop(&stack);// mendeclare sebuah variabel sebagai penghapus tanda kurung buka di stack
        } else if (isOperator(infix[i])){// mendeclare suatu kondisi jika karakter merupakan operator,--
            while (stack.top != -1 && stack.notasi[stack.top] != '(' && getPrecedence(infix[i]) <= getPrecedence(stack.notasi[stack.top])){
                postfix[j] = pop(&stack);// maka program akan mempop elemen di stack selama elemen teratas pada stack bukan tanda kurung buka, dan nilai prioritas operator yang sedang diproses lebih rendah atau sama dengan nilai prioritas operator pada elemen teratas stack
                j++;
            }
            push(&stack, infix[i]);// mendeclare sebuah variabel untuk mempush operator ke dalam stack
        }
    }

    while (stack.top != -1){// mendeclare sebuah fungsi untuk mempop elemen di stack yang masih tersisa
        postfix[j] = pop(&stack);
        j++;
    }
    postfix[j] = '\0';
}

int main(){// mendeclare fungsi main untuk memproses input dari code yang telah dibuat dan menampilkan output kepada user sesuai dengan apa yang hendak diketahui user
    char infix[MAX_SIZE], postfix[MAX_SIZE];//mendeclare 2 array untuk menyimpan karakter infix dan positif dan membatasi jumlahnya sesuai dengan declare maximum size yang sudah dibuat sebelumnya
    printf("Masukkan ekspresi infix: ");// mendeclare suatu command dan menampilkan kepada user untuk memasukkan ekspresi infix 
    fgets(infix, MAX_SIZE, stdin);// membaca inputan dari pengguna
    infix[strlen(infix) - 1] = '\0';// mendeclare sebuah variabel untuk menghapus karakter dari baris baru di akhir inputan dari string infix
    infixToPostfix(infix, postfix);// mendeclare sebuah fungsi untuk dapat mengubah ekspresi infix menjadi positif
    printf("Ekspresi postfix: %s\n", postfix);// mendeclare suatu command dan menampilkan kepada user ekspresi positif dari ekspresi infix yang telah diinputkan user sebelumnya
    return 0;// mendeclare suatu variabel untuk Mengembalikan nilai 0 dan sebagai penanda bahwa program berjalan dengan sukses
}
