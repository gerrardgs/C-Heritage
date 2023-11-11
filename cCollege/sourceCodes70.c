#include <stdio.h>

int main() {

    int angka[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int find;
    int awal = 0, akhir = sizeof(angka) / 4 - 1, tengah = (awal + akhir) / 2;

    printf("Input angka yang ingin dicari : ");
    scanf("%d", &find);

    while (1)
    {
        tengah = (awal + akhir) / 2;
        printf ("awal[%d], tengah[%d], akhir[%d]\n", awal, tengah, akhir);
        if (find == angka[tengah])
        {
            printf("data %d ditemukan di index ke %d\n", find, tengah);
            break;
        }
        else if (awal == akhir)
        {
            printf("data tidak ditemukan");
            break;
        }
        else if(find > angka[tengah])
        {
            awal = tengah + 1;
        }
        else if (find < angka[tengah])
        {
            akhir = tengah - 1;
        }           
    }
}
