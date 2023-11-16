#include <stdio.h>

int main(){
    int arr[3][2] = {{3,6},{9,8},{15,10}}; // Mendeklarasi Array 2 Dimensi
    for(int y = 0; y < 3; y++){ // Menginput Nilai Array Menggunakan Looping atau Perulangan
        for(int z = 0; z < 2; z++){
            printf("Nilai array x [%d][%d] adalah: %d\n", y, z, arr[y][z]);
        }
    }
}
