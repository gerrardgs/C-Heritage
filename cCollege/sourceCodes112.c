#include <stdio.h>

int* func(){
    int num = 10;
    return &num;
}

int main(){
    int *ptr = NULL;
    ptr = func();
    printf("%d", *ptr);
    return 0;
}
