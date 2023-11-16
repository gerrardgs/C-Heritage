// No. 1
#include <stdio.h>

struct Barang{ // mendeclare struktur barang dengan 3 tipe data
    char nama[50];
    int modal;
    int jual;
};

int main(){ // mendeclare variabel barang yang bertipe data barang dan margin yang bertipe data int
    struct Barang barang;
    int margin;

    printf("Nama: "); // mendeclare yang menghasilkan output yang nantinya akan dimasukkan user, yaitu berupa nama, modal. dan jual.
    scanf("%s", barang.nama);
    printf("Modal: ");
    scanf("%d", &barang.modal);
    printf("Jual: ");
    scanf("%d", &barang.jual);

    margin = barang.jual - barang.modal; // mendeclare output yang sdh diberikan user lalu program menentukan nilai margin yang didapat dengan mengurangi barang jual dengan barang modal 
    printf("Margin adalah: %d\n", margin); // mendeclare output berupa hasil margin yang telah didapat
    return 0; // declare - mengembalikkan nilai dari program menjadi 0
}
