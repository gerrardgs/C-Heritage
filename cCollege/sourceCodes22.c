#include <stdio.h>

void Ascending(int *angka, int size)
{
    for (int a = 0; a < size - 1; a++)
    {
        for (int b = 0; b < size - 1 - a; b++)
        {
            if (angka[b] > angka[b + 1])
            {
                int tmp = angka[b];
                angka[b] = angka[b + 1];
                angka[b + 1] = tmp;
            }
        }
    }
    tampil(angka, size);
}

void Descending(int *angka, int size)
{
    for (int a = 0; a < size - 1; a++)
    {
        for (int b = 0; b < size - 1 - a; b++)
        {
            if (angka[b] < angka[b + 1])
            {
                int tmp = angka[b];
                angka[b] = angka[b + 1];
                angka[b + 1] = tmp;
            }
        }
    }
    tampil(angka, size);
}

void tampil(int *angka, int size)
{
    system("cls");
    for (int a = 0; a < size; a++)
    {
        printf("[%d]", angka[a]);
    }
}

int binarySearch(int cari, int *arr, int right)
{
    int left = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (cari == arr[mid])
            return mid;
        if (cari > arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int angka[10];
    int size = sizeof(angka) / sizeof(angka[0]);
    int pilihan;
    do
    {
        printf("\n1. Masukkan Angka\n2. Ascending\n3. Descending\n4. Cari Angka\n5.Exit\nMasukkan Pilihan : ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            for (int a = 0; a < size; a++)
            {
                printf("Masukkan angka ke - %d : ", a + 1);
                scanf("%d", &angka[a]);
            }
            system("cls");
        }
        else if (pilihan == 2)
        {
            Ascending(angka, size);
        }
        else if (pilihan == 3)
        {
            Descending(angka, size);
        }
        else if (pilihan == 4)
        {
            Ascending(angka, size);
            int cari;
            printf("\nMasukkan Angka yang Dicari : ");
            scanf("%d", &cari);
            int resultIndex = binarySearch(cari, angka, size - 1);
            if (resultIndex == -1)
                printf("Angka tidak ditemukan\n");
            else
                printf("Angka %d ada di index %d\n", cari, resultIndex);
        }
    } while (pilihan != 5);
    system("cls");
    printf("Terimakasih Telah Menggunakan Aplikasi Ini :D");
}
