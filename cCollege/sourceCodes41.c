#include <stdio.h>

void InsertionSort(int angka[], int panjang)
{
    for (int a = 1; a < panjang; a++)
    {
        if (angka[a] < angka[a - 1])
        {
            int b = a;
            while (angka[b] < angka[b - 1] && b > 0)
            {
                int tmp = angka[b];
                angka[b] = angka[b - 1];
                angka[b - 1] = tmp;
                b--;
            }
        }
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
    int angka[] = {10, 5, 3, 1, 2, 9, 7, 4, 6};
    int panjang = sizeof(angka) / sizeof(int);
    InsertionSort(angka, panjang);
    show(angka, panjang);
}
