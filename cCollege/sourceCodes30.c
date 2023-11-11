//Function Pass By Value
//Program menukar dua bilangan

#include <stdio.h>

void tukar (int a, int b);

int main () {

  int x, y;

    scanf ("%d", &x);
    scanf ("%d", &y);
    printf ("\nBilangan x dan y sebelum ditukar : %d, %d", x, y);

    tukar (x, y);

  return 0;
}

void tukar (int a, int b) {

  int temp;
  temp = a;
  a = b;
  b = temp;
  printf ("\n\nBilangan x dan y sesudah ditukar melalui prosedur : %d, %d", a, b);

}
