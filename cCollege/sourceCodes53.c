#include <stdio.h>

int main() {

  int a;

  printf ("Masukkan Nilai Anda: ");
  scanf ("%d", &a);

  switch (a > 10) {
    case 1:
      printf ("\nNilai bernilai 1");
      break;
    case 0:
      printf ("\nNilai bernilai 2");
      break;
  default:
      printf ("\nNilai bukan 1 atau 2");
  }

}
