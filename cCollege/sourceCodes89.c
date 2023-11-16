#include <stdio.h>
#define maxfloors 10 // Jumlah maks dari lantai

int main(){
    int floors[maxfloors] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Menginput Urutan Elemen array dari 1-10 serta lantai yang dipilih
    int currentfloor;
    int y, z;

    printf("Masukkan nomor lantai: "); // Menampilkan output berupa lantai yang akan dipilih oleh user
    scanf("%d", &currentfloor);

    int currentfloorx = -1; // Mendeklarasikan index dari lantai yang dipilih oleh user
    for(y = 0; y < maxfloors; y++){
        if(floors[y] == currentfloor){
            currentfloorx = y;
            break;
        }
    }
    if(currentfloorx == -1){
        printf("Lantai yang dipilih tidak valid.\n"); // Dengan Fungsi, Menampilkan output seperti itu ketika user menginputkan no. lantai yang tidak valid
    } else{ // Jika user menginputkan no. lantai dengan benar, maka akan tampil 5 urutan layar pada layar lift
        int firstfloorx = currentfloorx - 2; // Mendeklarasikan indeks dari lantai pertama yang akan ditampilkan dan indeks dari lantai terakhir yang akan ditampilkan
        if(firstfloorx < 0){ // Jika indeks dari lantai pertama kurang dari 0, program mengubahnya menjadi 0 agar tidak terjadi error pada array
            firstfloorx = 0;
        }
        int lastfloorx = firstfloorx + 4;
        if(lastfloorx >= maxfloors){ // Jika indeks dari lantai terakhir lebih besar sama dengan maxfloors, maka maksfloors otomatis akan menjadi maxfloors-1
            lastfloorx = maxfloors - 1; // Lalu indeks dari lantai pertama akan diubah sehingga output berupa 5 lantai tertampilkan 
            firstfloorx = lastfloorx - 4; // Jika ditemukan, maka program akan menampilkan output berupa 5 urutan lantai pada layar lift
        }
        for(z = firstfloorx; z <= lastfloorx; z++){ // Lalu program akan melakukan iterasi pada array floors dari indeks lantai pertama, (lanjut dibawah)
            printf("%d ", floors[z]); // -hingga ;amtao terakhir dan output berupa nilai setiap elemen akan tertampilkan
        }
        printf("\n"); // fyi, iterasi dapat diartikan sebagai suatu proses atau metode yang digunakan secara berulang-ulang (pengulangan)-
    }// -dalam menyelesaikan suatu permasalahan
}
