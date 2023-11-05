#include <stdio.h>

int main(){
    int angka[] = {4, 5, 3, 1, 2, 8, 7, 6, 10, 9};
    int size = 10;
    int find;
    int awal = 0, akhir = sizeof(angka) / 4 - 1, tengah = (awal + akhir) / 2;

    int a, b, c, d, operasi, hasil;

    printf ("\tPilih Menu :\n");
    printf ("\t1. Ascending\n");
    printf ("\t2. Descending\n");
    printf ("\t3. Binary Searching\n");
    printf ("\t4. Exit\n");

    printf ("Pilih Jenis Operasi : ");
    scanf ("%d", &operasi);

    for (int a = 0; a < (size-1); a++)
        {
            for (int b = 0; b < size-a-1; b++)
            {
                if (angka[b] > angka[b+1])
                {
                    int temp = angka[b];
                    angka[b] = angka[b+1];
                    angka[b+1] = temp;
                }    
            }        
        }

    switch (operasi) {
    case 1:
        
        for (int a = 0; a < size; a++)
        {
            printf("[%d] ", angka[a]);
        } break;

    case 2:
        for (int a = size - 1; a >= 0; a--)
        {
            printf("[%d] ", angka[a]);
        } break;

    case 3:

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
    } break;
  }
}
