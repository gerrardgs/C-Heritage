#include <stdio.h>

void main() {
  
  char NamaLengkap[20];
  char NamaLengkap2[20];
  char NamaLengkap3[20];

  printf ("Masukkan Nama Lengkap pertama Anda: ");
        scanf ("%s", &NamaLengkap);
        printf ("\nHello %s", NamaLengkap);

  printf ("\n\nMasukkan Nama Lengkap kedua Anda: ");
        scanf ("%[^\n]s", &NamaLengkap2);
        printf ("\nHello %s", NamaLengkap2);

  printf ("\n\nMasukkan Nama Lengkap ketiga Anda: ");
        gets (NamaLengkap3);
        printf ("\nHello %s", NamaLengkap3);
}
