#include <stdio.h>

int main() {

  int nilai;

  printf ("Masukkan Nilai Anda: ");
  scanf ("%d", &nilai);

  if (nilai > 80) {
    printf ("Predikat A\n");
  } else {
    printf ("Predikat Bukan A\n");  
  }
    printf ("Program Selesai");
  
}
