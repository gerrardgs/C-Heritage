#include <stdio.h>

int main() {
    int arr[70];
    int sum = 0;
    float average;

    // mengisi array dengan angka 1-70
    for (int i = 0; i < 70; i++) {
        arr[i] = i + 1;
    }

    // menghitung jumlah seluruh elemen array
    for (int i = 0; i < 70; i++) {
        sum += arr[i];
    }

    // menghitung rata-rata dari seluruh elemen array
    average = (float) sum / 70;

    // menampilkan array dan rata-rata
    printf("Array: ");
    for (int i = 0; i < 70; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Rata-rata: %.2f", average);

    return 0;
}

//Dalam program di atas, kami menginisialisasi array arr dengan angka 1-70 menggunakan loop for. 
//Selanjutnya, kami menghitung jumlah seluruh elemen array menggunakan loop for kedua dan menyimpan hasilnya dalam variabel sum. 
//Kami kemudian menghitung rata-rata dari seluruh elemen array dengan membagi sum dengan jumlah elemen dalam array (70), 
//dan menyimpan hasilnya dalam variabel average. Terakhir, kami menampilkan array dan rata-rata menggunakan fungsi printf.
