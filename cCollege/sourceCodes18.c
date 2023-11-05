#include <stdio.h>

int main() {
  
  int matrix[2][3] = {{1, 2, 3},{3, 4, 5}};
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[1][0] = 3;
  printf ("%d\n", matrix[0][0]);

  char DaftarNama[2][100] = {
    "Saman",
    "Brembo"
  };
  printf ("nama 1 = %s\n", DaftarNama[0]);
  printf ("nama 2 = %s", DaftarNama[1]);

}
