#include <stdio.h>

int main() {

  int arrsatu[5] = {1,2,3,4,5}; //cara pertama
  int arrdua[] = {1,2,3}; //cara pertama tanpa panjang array
  int arrtiga [5]; //cara kedua
      arrtiga[0] = 1;
      arrtiga[1] = 2;
      arrtiga[2] = 3;
  float arrempat[5] = {1.2, 1.3, 1.4, 1.5, 1.6};
  double arrlima[5] = {1.5, 2.1, 3.0, 4.5, 5.1};
  //cara akses array
    printf ("%d %d %d %d %d", arrsatu[0], arrsatu[1], arrsatu[2], arrsatu[3], arrsatu[4]);
    printf ("\n%d", arrdua[2]);
    printf ("\n%d", arrtiga[1]);
  //ubah nilai array / manipulasi nilai array
      arrsatu[1] = 10;
      arrdua[2] += 10; //arrdua[2] = arrdua[2] + 10
      arrlima[3] *= 2;
    printf ("\n%d %d dan %.1f", arrsatu[1], arrdua[2], arrlima[2]);
    printf ("\n%.1f", arrempat[2]);
  //cara menginput data ke array (disini saya akan menginputkan angka ke arrtiga karena masih ada 3 slot yang kosong)
    printf ("\nMasukkan Angka yang ingin anda inputkan: ");
    scanf ("%d", &arrtiga[3]);
    printf ("%d", arrtiga[3]);

}
