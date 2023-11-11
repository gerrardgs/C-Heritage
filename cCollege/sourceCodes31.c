//Function Pass By Reference
//Program menukar dua bilangan

#include <stdio.h>

void passbyref (int *a, int *b);

int main () {

  int x, y;

    scanf ("%d", &x);
    scanf ("%d", &y);
    printf ("\nBilangan x dan y sebelum ditukar : %d, %d", x, y);

    passbyref (&x, &y);
    printf ("\n\nBilangan x dan y sesudah ditukar melalui prosedur : %d, %d", x, y);

  return 0;
}

void passbyref (int *a, int *b) {

  int temp;
  temp = *a;
  *a = *b;
  *b = temp;

}
