#include <stdio.h>

int main() {
  
  int angka[] = {3, 5, 8, 2, 1, 7, 9, 4, 6, 10};
  int panjang = sizeof(angka) / sizeof(angka[0]);
  int min, tmp;

  for (int a = 0; a < panjang; a++) {
    min = a;
    for (int b = a; b < panjang; b++)
    {
      if (angka[b] < angka[min]) {
          min = b;
      }
    }
    tmp = angka[a];
    angka[a] = angka[min];
    angka[min] = tmp;
  }
  for (int a = 0; a < panjang; a++) {
       printf("[%d] ", angka[a]);
  }
}
