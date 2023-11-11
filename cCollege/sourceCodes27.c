#include <stdio.h>

int sum(int a)
{
    int hasil = 3.14 * a * a;
    return hasil;
}


void luas(int a) {
    printf("Luas lingkaran : %d", sum(a));
}

int main(void){
    int a;
    printf("Masukkan jari - jari lingkaran : ");
    scanf("%d", &a);
    luas(a);
    return 0;
}
