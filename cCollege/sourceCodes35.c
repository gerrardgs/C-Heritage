#include <stdio.h>

int multiply(int x, int z) {
    if(z == 1)
        return x;
    else
        return x + multiply(x, z - 1);
}

int main() {
    int a, b;
    printf("");
    scanf("%d", &a);
  
    printf("");
    scanf("%d", &b);

    printf("%d\n", multiply(a, b));
    return 0;
}
