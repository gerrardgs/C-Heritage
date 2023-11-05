#include <stdio.h>

int main() {

  int arrX[3][2] = {{3,6}, {9,8}, {15,10}};
  int cari;

  printf ("array : %d,", arrX[3][2]);
  printf("Masukkan elemen yang ingin dicari : ");
  scanf("%d", &cari);

  for (int a = 0; a < 3; a++)
  {
    for (int b = 0; b < 3; b++)
    {
      if (arrX[a][b] == cari)
      {
        printf("Elemen %d berada di indeks [%d][%d]\n", cari, a, b);
      }
      if ((a == 3 && b == 2) && arrX[a][b] != cari)
      {
        printf("Tidak ada elemen tersebut didalam array\n");
      }
    }
  }
}
