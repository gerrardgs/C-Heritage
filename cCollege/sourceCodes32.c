#include <stdio.h>

void passByValue (int i);
void passByReference (int *i);

//Program utama
int main() {

  int num1 = 11;

  passByValue (num1);
  printf ("\nBilangan num1 yaitu 11 setelah ditukar dengan pass by value = %d\n", num1);

  passByReference (&num1);
  printf ("Bilangan num1 yaitu 11 setelah ditukar dengan pass by value = %d", num1);

  return 0;
}

//Prosedur
void passByValue (int i) {
  i = 7;
  return;
}

void passByReference (int *i) {
  *i = 10;
  return;
}
