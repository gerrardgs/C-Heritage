#include <stdio.h>

struct Buku
{
    int id_buku;
    char  *judul;
    int tahun;
};

int main(){

        struct Buku buku1, buku2; // Bertipe data struct

        buku1.id_buku = 1; // Mamasukkan nilai ke struct buku 1
        buku1.judul = "Laskar Pelangi";
        buku1.tahun = 2012;
        
        buku2.id_buku = 2; // Memasukkan nilai ke struct buku 2
        buku2.judul = "Dilan Dilan";
        buku2.tahun = 2018;
        
        printf( "Buku 1 id : %d\n", buku1.id_buku); // print buku1 info
        printf( "Buku 1 judul : %s\n", buku1.judul);
        printf( "Buku 1 tahun : %d\n", buku1.tahun);
        
        printf( "Buku 2 id : %d\n", buku2.id_buku); // print buku2 info
        printf( "Buku 2 judul : %s\n", buku2.judul);
        printf( "Buku 2 tahun : %d\n", buku2.tahun);

        return 0;
}
