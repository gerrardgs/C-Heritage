#include <stdio.h>

float arrayMean(int arr[], int n){ // fungsi arrayMean bertipe data float yang memiliki 2 parameter, yaitu arr dengan tipe data n 
    int sum = 0; // variabel sum digunakan untuk menjumlahkan semua elemen pada array
    for (int i = 0; i < n; i++){ // Perulangan for untuk mengakses setiap elemen pada arr dan menambahkan nilai ke variabel sum
        sum += arr[i];
    }
    return(float)sum/n; // declare untuk mencari rata2 dan hasil akan dikembailkan ke float 
}
int main(){  // fungsi main dalam program 
    int n; // variabel n 
    scanf("%d", &n); // membaca input user yang bernilai n
    int arr[n]; // declare arr dengan jumlah elemen yang sama dengan n
    for (int i = 0; i < n; i++){ // perulangan for untuk mengakses setiap elemen arr
        scanf("%d", &arr[i]); // membaca input user
    }
    float mean = arrayMean(arr, n); // Rata2 dari semua elemen arr dihitung dengan menggunakan fungsi arrayMean, parameter arr & n, hasilnya disimpan dalam variabel mean
    printf("%.2f%%\n", mean); // output berupa hasil dari rata2

    return 0; // menandakan program selesai dijalankan dan mengembalikan nilai 0.
}
