#include <stdio.h>

int main() {

  int x = 5;
  int *ptr = &x;
  printf ("\nAlamat memori : %d dan Nilai : %d\n", &x, x);
  printf ("Nilai PTR : %d dan *PTR : %d\n", ptr, *ptr);
  *ptr = 10;
  printf ("Nilai X baru : %d", x);

}
