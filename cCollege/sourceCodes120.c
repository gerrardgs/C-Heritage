#include <stdio.h>

int multiply(int n1, int n2){
    return n1*n2;
}

int main(){
    int x = 2;
    int y = 3;
    int m = multiply(x,y);
    printf("%d",m);
    return 0;
}
