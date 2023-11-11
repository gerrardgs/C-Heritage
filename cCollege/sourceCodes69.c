#include <stdio.h>

int main()
{
    // deklarasi variabel
    int matriks[3][3];
    int baris;
    int kolom;

    // pengisian array
    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            printf("masukkan angka :\n");
            scanf("%d", &matriks[baris][kolom]);
            printf("\n");
        }
    }

    for (baris = 0; baris < 3; baris++)
    {
        for (kolom = 0; kolom < 3; kolom++)
        {
            printf("%d ", matriks[baris][kolom]);
        }
        printf("\n");
    }
    return 0;
}
