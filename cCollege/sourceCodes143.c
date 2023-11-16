#include <stdio.h>

// rekursif perulangan
void printRecurse(int n){
    if(n > 0){
        printf("Hello World\n");
        printRecurse(n - 1);
    }
}

void printTen(int n){
    if(n > 0){
        printTen(n - 1);
        printf("Hello World\n");
    }
}

int main(){
    int count = 10;
    printTen(count);
    return 0;
}
