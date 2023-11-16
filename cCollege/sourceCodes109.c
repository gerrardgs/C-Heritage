#include <stdio.h>

int main(){
    int x = 100;
    int *ptr = &x;
    int **ptr2 = &ptr;

    printf("x       = %d\n", x);
    printf("&x      = %d\n", &x);
    printf("\n");
    printf("ptr     = %d\n", ptr);
    printf("*ptr    = %d\n", *ptr);
    printf("&ptr    = %d\n", &ptr);
    printf("\n");
    printf("ptr2    = %d\n", ptr2);
    printf("*ptr2   = %d\n", *ptr2);
    printf("**ptr2   = %d\n", **ptr2);
}
