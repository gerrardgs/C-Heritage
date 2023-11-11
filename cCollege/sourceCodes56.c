#include <stdio.h>

int main() {

  //Pointer Integer
  int x = 5;
  int *ptr = &x;
  
  printf ("\nAlamat memori : %d dan Nilai : %d\n", &x, x);
  printf ("Nilai PTR : %d dan *PTR : %d\n", ptr, *ptr);
  
  *ptr = 10;
  printf ("Nilai X baru : %d\n\n", x);

  //Pointer Char
  char y = 'c';
  char *py = &y;

  printf ("Alamat Memori y : %d dan Nilai y : %c\n", &y, y);
  printf ("py : %d dan *py : %c\n", py, *py);
  
  *py = 'x';
  printf ("Nilai y baru : %c", y);

  //double pointer
  int **ptr2 = &ptr;
  printf ("Alamat ptr : %d\n", &ptr);
  printf ("Nilai ptr2 : %d dan **ptr2 : %d\n", ptr2, **ptr2);
}
