#include <stdio.h>

void InsertionSort(int angka[], int panjang)
{
    for (int a = 1; a < panjang; a++)
    {
        int key = angka[a];
        int b = a - 1;
        while (b >= 0 && angka[b] > key)
        {
            angka[b + 1] = angka[b];
            b = b - 1;
        }
        angka[b + 1] = key;
    }
}

void show(int angka[], int panjang)
{
    for (int a = 0; a < panjang; a++)
    {
        printf("%d ", angka[a]);
    }
}

int main()
{
    int angka[] = {1, 9, 4, 5, 6, 7, 2, 3, 8, 1, 9, 4, 5, 6, 7, 2, 3, 8};
    
    int panjang = sizeof(angka) / sizeof(int);
    InsertionSort(angka,panjang);
    show(angka,panjang);
}
