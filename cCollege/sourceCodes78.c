#include <stdio.h>

int main() {
    // inisialisasi array
    int x[5] = {15, 21, 4, 6, 2};

    // menampilkan elemen sebelum diurutkan
    printf("Sebelum diurutkan:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    // mengurutkan elemen pada array x
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (x[i] > x[j]) {
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    // menampilkan elemen setelah diurutkan
    printf("Setelah diurutkan:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    return 0;
}

//Penjelasan program:
//Pertama-tama, array x diinisialisasi dengan nilai-nilai yang diberikan dalam soal.
//Kemudian, program menampilkan elemen-elemen pada array x sebelum diurutkan menggunakan perulangan for.
//Selanjutnya, program mengurutkan elemen-elemen pada array x menggunakan nested loop for 
//yang berfungsi untuk membandingkan setiap elemen pada array dan menukar posisi elemen 
//apabila ditemukan elemen yang lebih kecil dari elemen yang dibandingkan.
//Setelah elemen pada array x terurut, program menampilkan elemen-elemen pada array x 
//setelah diurutkan menggunakan perulangan for.
//Program selesai.
