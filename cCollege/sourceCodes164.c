/*Tugas No 3*/
#include <stdio.h>

typedef struct coordinatTrapesium{ // struck digunakan untuk menyimpan data dengan banyak data
    int x; //data kordinat trapesium x
    int y; // data korordinat trapesium y
}Trapesium;

int main(){

    Trapesium var[6]; // deklarasi struct trapesium dengan variable var

    for (int i = 0; i < 6; i++){
        printf ("Koordinat Titik %c (x,y): ", 65+i);
        scanf ("%d %d", &var[i].x, &var[i].y);
        // printf dan scanf digunakan untuk mengambil input dari user ke dalam variable variable yang diinginkan 
    }

    printf ("Luas trapesium : %.2f", 0.5 * (var[0].y - var[2].y) * ((var[1].x - var[0].x) + (var[5].x - var[4].x)));
    // dengan rumus dari trapesium dimana L = 1/2 t ( a + b )
    // dimana t = var[0].y - var[2].y
    //dimana a = var[1].x - var[0].x
    //dimana b = var[5].x - var[4].x
}
