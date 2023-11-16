#include <stdio.h>

int main()
{
    float arrFloat[10];
    float arrF[] = {1, 2, 3, 4, 5};
    int n = 3;
    int arrN[n];
    int arrX[5] = {1, 2, 3};

    printf("%d", arrX[15]);

    arrF[15] = 7;
    printf("%f", arrF[15]);

    printf("\n\nAlamat Memory Index Pertama: %d", arrF);
    printf("\n\nAlamat Memory Index 15 %d", (arrF + 1));
}
