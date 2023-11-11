#include <stdio.h>

int main() {

  int angka3, angka4, operasi, hasilsisa;
  float angka1, angka2, hasil;

  printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf ("\t   PROGRAM KALKULATOR\n");
  printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  printf ("\tJenis Operasi :\n");
  printf ("\t1. Penjumlahan\n");
  printf ("\t2. Pengurangan\n");
  printf ("\t3. Perkalian\n");
  printf ("\t4. Pembagian\n");
  printf ("\t5. Sisa Bagi\n");

  printf ("Pilih Jenis Operasi : ");
  scanf ("%d", &operasi);
  printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  printf ("Masukkan bilangan pertama : ");
  scanf ("%f", &angka1, "%d", &angka3);
  printf ("Masukkan bilangan kedua   : ");
  scanf ("%f", &angka2, "%d", &angka4);

  if (operasi == 1) {
      hasil = angka1 + angka2;
      printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ +");
      printf ("\nHasil\t\t\t  : %.2f\n", hasil);
  }
  else if (operasi == 2) {
      hasil = angka1 - angka2;
      printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -");
      printf ("\nHasil\t\t\t  : %.2f\n", hasil);
  }
  else if (operasi == 3) {
      hasil = angka1 * angka2;
      printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ x");
      printf ("\nHasil\t\t\t  : %.2f\n", hasil);
  }
  else if (operasi == 4) {
      hasil = angka1 / angka2;
      printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ :");
      printf ("\nHasil\t\t\t  : %.2f\n", hasil);
  }
  else if (operasi == 5) {
      hasilsisa = angka3 % angka4;
      printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
      printf ("\nHasil\t\t\t  : %d\n", hasilsisa);
  }
  else {
    printf ("Maaf, anda salah menginputkan operasi!");
  } 

}
