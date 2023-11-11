#include <stdio.h>

void luaslingkaran(float *luas, float radius)
{
    *luas = 3.14 * radius * radius;
}

int main(){
    float luas = 0, radius;
    printf("Masukkan jari - jari lingkaran : ");
    scanf("%f", &radius);
    luaslingkaran (&luas, radius);
    printf("\nLuas Lingkaran : %.2f", luas);
}
