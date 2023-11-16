#include <stdio.h>

int main() {
  int x[3][2]; // deklarasi array 2 dimensi
  
  // mengisi nilai array menggunakan perulangan
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      if (i == 0 && j == 0) {
        x[i][j] = 3;
      } else if (i == 0 && j == 1) {
        x[i][j] = 6;
      } else if (i == 1 && j == 0) {
        x[i][j] = 9;
      } else if (i == 1 && j == 1) {
        x[i][j] = 8;
      } else if (i == 2 && j == 0) {
        x[i][j] = 15;
      } else if (i == 2 && j == 1) {
        x[i][j] = 10;
      }
    }
  }

  // menampilkan isi array
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      printf("Nilai array x[%d][%d] adalah : %d\n", i, j, x[i][j]);
    }
  }
  
  return 0;
}
