#include <stdio.h>

void barisSatu(int angka[], int panjang)
{
  int angka2[panjang];
    for (int a = 0; a < panjang; a++)
    {
      angka2[a] = angka[a];
    }
    for (int a = 1; a < panjang; a++)
    {
      int key = angka2[a];
      int b = a - 1;
        while (b >= 0 && angka2[b] > key)
        {
            angka2[b + 1] = angka2[b];
            b = b - 1;
        }
      angka2[b + 1] = key;
    }
    for (int a = panjang / 2 + 1; a < panjang; a++) {
      int key = angka2[a];
      int b = a - 1;
        while (b >= panjang / 2 + 1 && angka2[b] < key)
        {
            angka2[b + 1] = angka2[b];
            b = b - 1;
        }
        angka2[b + 1] = key;
    }
    printf("Baris 1 : ");
    show(angka2, panjang);
}

void barisDua(int angka[], int panjang) 
{
  int angka2[panjang];
    for (int a = 0; a < panjang; a++)
    {
      angka2[a] = angka[a];
    }
    for (int a = 1; a < panjang; a++)
    {
      int key = angka2[a];
      int b = a - 1;
        while (b >= 0 && angka2[b] > key)
        {
            angka2[b + 1] = angka2[b];
            b = b - 1;
        }
      angka2[b + 1] = key;
    }
    printf("Baris 2 : ");
    show(angka2, panjang);
}

void show(int angka[], int panjang)
{
  for (int a = 0; a < panjang; a++)
  {
      printf("%d ", angka[a]);
  }
  printf("\n");
  
}

int main()
{
  int angka[] = {1, 9, 4, 5, 6, 7, 2, 3, 8, 1, 9, 4, 5, 6, 7, 2, 3, 8};
  int panjang = sizeof(angka) / sizeof(int);
  barisSatu(angka,panjang);
  barisDua(angka,panjang);
}
