#include <stdio.h>
#include <stdbool.h>

int main() {

  int a, b, c, d;
    a = 10;
    b = 5;
    c = 2;
    d = 15;

  printf ("%d\n", (a > b) && (a < d));
  printf ("%d\n", (a >= b) || (c == d));


}
