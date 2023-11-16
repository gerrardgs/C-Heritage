#include <stdio.h>

int main(){
    int arr[70]; // Menginputkan elemen aray, komponen penghitung penjumlahan dan rata-rata
    int sum = 0;
    float average;
    for(int y = 0; y < 70; y++){ // Proses mengisi array dengan angka 1-70
        arr[y] = y+1;
    }
    for(int y = 0; y < 70; y++){ // Proses menghitung (menjumlahkan) dari seluruh elemen array
        sum += arr[y];
    }
    average = (float) sum / 70; // Proses menghitung (mencari rata-rata) dari seluruh elemen array
    printf("array : "); // Menampilkan output berupa array yang terdiri dari angka 1-70
    for(int y = 0; y < 70; y++){
        printf("%d ", arr[y]);
    }
    printf("\n");
    printf("rata - rata dari array tersebut adalah : %.2f", average); // Menampilkan output berupa rata-rata dari seluruh elemen array yang sudah dijumlahkan sebelumnya
}
// Elemen array diinput dan dihitung menggunakan loop for
