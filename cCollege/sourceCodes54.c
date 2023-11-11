#include <stdio.h>

int main() {

  //Pointer ke Array
  int Array1[5] = {1, 2, 7, 4, 5};
  int *pArr = &Array1;

  for (int a = 0; a < 5; a++)
  {
    printf ("Alamat : %d pArr : %d\n", pArr, *pArr + a);
  }

  printf ("\n");

  //Akses Nilai Array lewat Pointer
  for (int a = 0; a < 5; a++)
  {
    printf ("Alamat : %d pArr : %d\n", (pArr + a), *(pArr + a));
  }

}
