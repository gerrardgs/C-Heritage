#include <stdio.h>

int main() {
  
  int c, d, operasi, hasilsisa;
  float a, b, hasil;

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

  switch (operasi) {
    case 1:
        printf ("\nOperasi Penjumlahan :\n");
        printf ("Masukan bilangan pertama : ");
        scanf ("%f", &a);
        printf ("Masukan bilangan kedua   : ");
        scanf ("%f", &b);
              hasil = a + b;
        printf ("\nHasil\t\t\t : %.2f\n", hasil);
      break;
    case 2:
        printf ("\nOperasi Pengurangan :\n");
        printf ("Masukan bilangan pertama : ");
        scanf ("%f", &a);
        printf ("Masukan bilangan kedua   : ");
        scanf ("%f", &b);
              hasil = a - b;
        printf ("\nHasil\t\t\t : %.2f\n", hasil);
      break;
    case 3:
        printf ("\nOperasi Perkalian :\n");
        printf ("Masukan bilangan pertama : ");
        scanf ("%f", &a);
        printf ("Masukan bilangan kedua   : ");
        scanf ("%f", &b);
              hasil = a * b;
        printf ("\nHasil\t\t\t : %.2f\n", hasil);
      break;
    case 4:
        printf ("\nOperasi Pembagian :\n");
        printf ("Masukan bilangan pertama : ");
        scanf ("%f", &a);
        printf ("Masukan bilangan kedua   : ");
        scanf ("%f", &b);
              hasil = a / b;
        printf ("\nHasil\t\t\t : %.2f\n", hasil);
      break;
    case 5:
        printf ("\nOperasi Sisa Bagi :\n");
        printf ("Masukan bilangan pertama : ");
        scanf ("%d", &c);
        printf ("Masukan bilangan kedua   : ");
        scanf ("%d", &d);
              hasilsisa = c % d;
        printf ("\nHasil\t\t\t : %d\n", hasilsisa);
      break;
    default: 
        printf("Maaf, anda salah memilih menu!");
      break;
    }
    return 0;
}
