#include <stdio.h>

int main(){
    int arr[3][2] = {{3,6},{9,8},{15,10}}; // Mendeklarasikan Elemen array, bersamaan dengan variabel y & z.
    int y, z, look, fals=0; // Mendeklarasikan look dan fals. look digunakan untuk menyimpan atau mencari nilai array
    printf("array : "); // Sedangkan fals digunakan untuk mengecek nilai array apakah ada atau tidak
    for(int y = 0; y < 3; y++){ // Menampilkan output berupa nilai array
        for(int z = 0; z < 2; z++){
            printf("%d ,", arr[y][z]);
        }
    }
    printf("\nMasukkan elemen yang ingin dicari indeksnya : "); // Menampilkan Output yang diarahkan ke user untuk mencari nilai array yang hendak dicari oleh user
    scanf("%d", &look); 

    for(int y = 0; y < 3; y++){ // Nilai array dicari dengan menggunakan perulangan for  
        for(int z = 0; z < 2; z++){
            if(arr[y][z] == look){ // Jika nilai array ditemukan, maka program akan menampilkan output seperti yang ada dibawah ini, begitupun sebaliknya
                printf("Elemen %d berada di indeks[%d][%d]\n", look, y, z);
                fals=1;
            }
        }
    }
    if(fals==0){
        printf("Tidak ada elemen tersebut di dalam array");
    }
}
// Program ini berjalan menggunakan nested loop
