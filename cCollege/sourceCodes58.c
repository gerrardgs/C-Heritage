#include <stdio.h>

int main() {
int waktu = 0;

  // membuat pointer yang mereferensikan alamat dari variabel waktu
  int *p_waktu = &waktu;

  // mengakses variabel time melalui pointer
  printf("Value *p_waktu = %d\n", *p_waktu);
  printf("Value waktu awal = %d\n", waktu);

  // mengubah data variabel time melalui pointer
  *p_waktu = 5;

  // melihat value dari variabel waktu
  printf("Value waktu setelah diubah = %d\n", waktu);

  return 0;
}
