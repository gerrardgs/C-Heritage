#include <stdio.h>

int main() {
    int arr[3][2] = {{3,6},{9,8},{15,10}};
    int i, j, cari, flag=0;

    // Menampilkan array
    printf("Array: \n");
    for(i=0; i<3; i++) {
        for(j=0; j<2; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Mencari indeks elemen yang diinginkan
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &cari);

    for(i=0; i<3; i++) {
        for(j=0; j<2; j++) {
            if(arr[i][j] == cari) {
                printf("Nilai %d berada di indeks [%d][%d]\n", cari, i, j);
                flag=1;
            }
        }
    }

    if(flag==0) {
        printf("Nilai tidak ditemukan dalam array\n");
    }

    return 0;
}
