// No. 3
#include <stdio.h>
#include <math.h>

typedef struct coordinatTrapesium{ // declare struktur coordinatTrapesium dengan 2 variabel berbeda.
    int x;
    int y;
}Trapesium;

int main(){
    Trapesium segitiga[6]; // mendeclare fungsi main array dari struktur trapesium bernama segitiga yg berisi 6

    for (int a=0; a<6; a++){ // mendeclare perulangan for dan menghasilkan output yang nantinya diinput user , yaitu nilai2 yang nantinya diterima dan disimpan didalam array segitiga 
        printf ("Koordinat Titik %c (x,y): ", 65+a); // dan format yang digunakan menggunakan karakter
        scanf ("%d %d", &segitiga[a].x, &segitiga[a].y); 
    }

    float c = segitiga[0].y - segitiga[2].y; // mendeclare perhitungan pada program bertipe data float. yang dihitung adalah nilai c, d dan e yang nantinya dipakai dalam menentukan luas trapesium.
    float d = segitiga[1].x - segitiga[0].x; 
    float e = segitiga[5].x - segitiga[4].x;

    printf ("Luas trapesium : %.2f", ((d + e) * c/2)); // mendeclare output dari perhitungan luas trapesium menggunakan rumus tersebut dan output yang dihasilkan berupa bilangan bertipe data float
}
