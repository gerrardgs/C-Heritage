#include <stdio.h>

int main() {
    int a;
    int nilai = a;

    if (nilai > 80 && nilai <= 100) {
        printf("Nilai Anda A");
        if (nilai == 100) {
            printf("Selamat!!!, nilai Anda Sempurna");
        } else if (nilai == 99) {
            printf("Selamat!!!, nilai Anda nyaris Sempurna");
        } else {
            printf("Selamat!!!");
        }
    } else if (nilai > 70 && nilai <= 80) {
        printf("Nilai Anda B");
    } else {
        printf("Nilai Anda C");
    }

    return 0;
}
