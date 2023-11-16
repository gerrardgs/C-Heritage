#include <stdio.h>

int main(){
    int arr[5] = {15, 21, 4, 6, 2}; // Menginputkan Nilai Array
    printf("Array Awal : \n"); // Mendeklarasikan Output Array Sebelum Disusun Secara Berurutan
    for(int y = 0; y < 5; y++){
        printf("%d, ", arr[y]);
    }
    printf("\n");
    for(int y = 0; y < 5-1; y++){ // Proses Mengurutkan Array Dari Array Awal
        for(int z = y+1; z < 5; z++){ // Proses Mengurutkan Elemen Array Menggunakan Nested Loop For
            if(arr[y] > arr[z]){
                int temp = arr[y];
                arr[y] = arr[z];
                arr[z] = temp;
            }
        }
    }
    printf("Array yang telah diurutkan : \n"); // Mendeklarasikan Output Array Setelah Selesai Diurutkan
    for(int y = 0; y < 5; y++){
        printf("%d, ", arr[y]);
    }
}
