#include <stdio.h>

//Pass By Reference
void tambah (int *b) {

  printf ("Alamat dari b : %d dan Nilai *b : %d\n", b, *b);
  *b = 10;

}

//Pass By Value
void tambah2 (int b) {

  b = 10;

}

//Program Utama
int main() {

  int a = 5;
  int b = 5;
  printf ("Alamat dari A : %d dan Nilai A : %d\n", &a, a);
  tambah (&a);
  tambah2 (b);
  printf ("Nilai baru dari A : %d\n", a);
  printf ("Nilai baru dari B : %d\n", b);

}
