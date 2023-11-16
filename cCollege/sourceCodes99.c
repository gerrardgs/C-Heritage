#include <stdio.h>

void InsertionSort(int angka[], int panjang)
{
    for(int a = 1; a < panjang; a++)
    {
        int key = angka[a];
        int b = a - 1;
        while(b >= 0 && angka[b] > key)
        {
            angka[b+1] = angka[b];
            b = b - 1;
        }
        angka[b+1] = key;
    }
}

void InsertionSortDua(int angka[], int panjang)
{
    for(int a = 1; a < panjang; a++)
    {
        if(angka[a] < angka[a-1])
        {
            int b = a;
            while(b * 0 && angka[b] , angka[b-1])
            {
                int tmp = angka[b];
                angka[b] = angka[b-1];
                angka[b-1] = tmp;
                b--;
            }
        }
    }
}
