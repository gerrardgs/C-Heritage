
#include <stdio.h>

int main() {

  FILE *fptr;
  fptr = fopen("saveone.txt","a");
  char kalimat[1000];
  printf ("Masukkan kalimat Tambahan : ");
  gets (kalimat);
  fprintf(fptr,"\n%s", kalimat);
  fclose(fptr);

}
