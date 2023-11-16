#include <stdio.h>

int main(){
    float sArr[5] = {5, 12, 40, 100, 72.5};
    for (int i = 0; i < 5; i++)
    {
        printf("Array %i: %.1f\n", i, sArr[i]);
    }
    return 0;
}
