#include <stdio.h>

int main() {

  FILE *fptr;
  fptr = fopen("saveone.txt", "w");
  char kalimat[1000];
  printf ("Masukkan Kalimat : ");
  gets (kalimat);
  fprintf (fptr, "%s", kalimat);
  fclose (fptr);

}
