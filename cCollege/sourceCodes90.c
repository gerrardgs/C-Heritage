#include <stdio.h>

#define MAX_FLOORS 10 // jumlah lantai maksimum

int main() {
    int floors[MAX_FLOORS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // urutan lantai
    int current_floor; // lantai yang dipilih
    int i, j;

    printf("Masukkan nomor lantai yang ingin dituju: ");
    scanf("%d", &current_floor);

    // menentukan indeks dari lantai yang dipilih
    int current_floor_index = -1;
    for (i = 0; i < MAX_FLOORS; i++) {
        if (floors[i] == current_floor) {
            current_floor_index = i;
            break;
        }
    }

    if (current_floor_index == -1) { // lantai yang dipilih tidak valid
        printf("Lantai yang dipilih tidak valid.\n");
    } else { // menampilkan 5 urutan lantai pada layar lift
        int first_floor_index = current_floor_index - 2;
        if (first_floor_index < 0) {
            first_floor_index = 0;
        }
        int last_floor_index = first_floor_index + 4;
        if (last_floor_index >= MAX_FLOORS) {
            last_floor_index = MAX_FLOORS - 1;
            first_floor_index = last_floor_index - 4;
        }
        for (j = first_floor_index; j <= last_floor_index; j++) {
            printf("%d ", floors[j]);
        }
        printf("\n");
    }

    return 0;
}
//Pertama-tama, kita definisikan konstanta MAX_FLOORS yang menyatakan jumlah lantai maksimum. 
//Kemudian, kita deklarasikan array floors yang berisi urutan lantai dari 1 hingga 10.
//Selanjutnya, kita meminta input dari user berupa nomor lantai yang ingin dituju, 
//dan menyimpannya ke dalam variabel current_floor.
//Kemudian, kita mencari indeks dari lantai yang dipilih dalam array floors. Jika lantai yang dipilih tidak ditemukan dalam array, 
//kita keluarkan pesan keUntuk menampilkan 5 urutan lantai, 
//kita menentukan indeks dari lantai pertama yang akan ditampilkan dan indeks dari lantai terakhir yang akan ditampilkan. 
//Jika indeks dari lantai pertama kurang dari 0, kita ubah menjadi 0 agar tidak terjadi index out of bound pada array. 
//Jika indeks dari lantai terakhir lebih besar dari atau sama dengan MAX_FLOORS, kita ubah menjadi MAX_FLOORS - 1, 
//dan kita ubah indeks dari lantai pertama sehingga kita selalu menampilkan 5 lantasalahan. Jika ditemukan, 
//kita lanjutkan dengan menampilkan 5 urutan lantai pada layar lift.
//i pada layar lift. Terakhir, kita melakukan iterasi pada array floors dari indeks lantai pertama 
//hingga lantai terakhir dan menampilkan nilai setiap elemenn
