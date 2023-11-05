#include <stdio.h>
  
int main(void)
{    
    // 1. Deklarasi Array dengan menspesifikasikan ukuran array
    int arr1[10];
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    // Deklarasi ukuran array dengan menggunakan variable
    int n = 10;
    int arr2[n];

    //2. Deklarasi Array dengan menginisialisasi elemen
    int arr3[] = { 10, 20, 30, 40};
    //Compiler akan membuat array berukuran 4, dengan cara ini ukuran dan elemen array telah dispesifikasi
	
    //3. Deklarasi array dengan menentukan ukuran dan menginisialisasi elemen
    int arr4[6] = { 10, 20, 30, 40 };
    //Compiler akan membuat array berukuran 6, dan akan mengisi indeks 0 - 3 dengan elemen yang ada
    //Index 4 - 5 akan di deklarasikan sebagai 0 
    // seperti "int arr[] = {10, 20, 30, 40, 0, 0}"
    
    printf("Nilai arr4 pada %i", arr4[4]);
    return (0);
}
