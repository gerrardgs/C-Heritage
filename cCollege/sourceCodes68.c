#include <stdio.h>

int main()
{

    int BarisAngka[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int cari;
    printf("Masukkan angka yang dicari : ");
    scanf("%d", &cari);
    for (int a = 0; a < sizeof(BarisAngka); a++)
    {
        if (BarisAngka[a] == cari)
        {
            printf("Angka %d ditemukan pada urutan ke %d\n", cari, a + 1);
            break;
        }
        else if (a == sizeof(BarisAngka) - 1 && BarisAngka[a] != cari)
        {
            printf("Angka tidak ditemukan\n");
        }
    }
}
