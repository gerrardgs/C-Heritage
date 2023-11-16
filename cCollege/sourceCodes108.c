#include <stdio.h>

int main (){
    int x = 100;
    int *ptr = &x;  // Variabel ptr

    printf("&x = %d\n", &x);
    printf("ptr = %d\n", ptr);
    printf("ptr = %d\n", *ptr);
    
    *ptr = 10;
    printf("x = %d", x);
}
