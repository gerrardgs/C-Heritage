#include <stdio.h>

float greatestOf (float *a, float *b, float *c, float *d){ // Fungsi greatestOf yang menyimpan 4 Alamat memori bertipe data float
    float max = *a; // Variabel max dengan petunjuk a yang berbasis data float
    if (*b > max && *b != *a && *b != *c && *b != *d){ // Inisiasi jika b > a dan tidak sama dengan bil. 1, 3, 4. Maka nilai max berubah menjadi b (bil. 2)
        max = *b;
        }
    if (*c > max && *c != *a && *c != *b && *c != *d){ // Inisiasi jika c > a dan tidak sama dengan bil. 1, 2, 4. Maka nilai max berubah menjadi c (bil. 3)
        max = *c;
        }
    if (*d > max && *d != *a && *d != *b && *d != *c){ // Inisiasi jika d > a dan tidak sama dengan bil. 1, 2, 3. Maka nilai max berubah menjadi d (bil. 4)
        max = *d;
        }
    return max; // Declare untuk mengembalikan nilai terbesar dari ke-4 Bilangan dari fungsi greatestOf
}
    int main(){ // fungsi main dalam program
        float a, b, c, d; // bertipe data Float yang berisikan 4 variabel yang akan digunakan untuk menyimpan 4 Bil. yang diinput oleh user
        scanf("%f %f %f %f", &a, &b, &c, &d); // Meminta pengguna untuk memasukkan 4 Bil. bertipe data Float dan menyimpannya didalam 4 variabel
        float max = greatestOf(&a, &b, &c, &d); // Manggil fungsi greatestOf lalu menyimpan nilai terbesar yang dikembalikan di variabel max
        printf("%.f%%\n", max); // Output berupa nilai terbesar yang tersimpan di variabel max 

        return 0; 
    }
