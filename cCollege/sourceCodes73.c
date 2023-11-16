#include <stdio.h>

void koboImaginaryChess (int i, int j, int size, int *chessBoard){ // Fungsi yang menerima 4 parameter yaitu i & j sebagai koordinat bidak pada catur , size sebagai ukuran papan catur, dan chessboard sebagai sebuah pointer arr yang akan menandai blok pada papan catur yang dapat dijangkau oleh knight pada koordinat i & j
    int arr2d[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}}; // mendefinisikan arr 2 dimensi sebagai presentator perpindahan yang mungkin dilakukan kuda pada saat permainan catur berlangsung 
    for (int x = 0; x < 8; x++){ // perulangan for diperlukan untung mengeksekusi fungsi sebelumnya dan akan dieksekusi sebanyak 8x (untuk setiap kemungkinan pergerakan kuda) 
        int y = i + arr2d[x][0]; // saat kuda bergerak, koordinat sel yang kemungkinan ditandai oleh catur akan dihitung dengan menambahkan koordinat relatif pergerakan kuda dari array dengan koordinat kuda saat itu yang akan disimpan dalam variabel y & z
        int z = j + arr2d[x][1]; // kemudian dilakukan pengecekan, apabila koordinat blok yang dihitung dalam permainan catur ada atau tidak. jika ada maka akan keluar nilai 1, jika tidak ada maka akan keluar nilai 0. 
        if(y >= 0 && y < size && z >= 0 && z < size){ // Hal itu dapat terjadi dengan mengakses elemen array menggunakan pointer aritmatika dengan menggeser pointer. dalam hal ini size adalah ukuran blok catur sehingga kondisional akan menghasilkan indeks dari elemen chessboard yang sesuai dengan koordinat
            *(chessBoard + y*size + z) = 1;
        }
    }
}
int main(){ // Mendeclare fungsi main
    int i, j;// variabel i & j bertipe data int
    scanf("%d %d", &i, &j);// membaca input user 
    int chessBoard[8][8] = {0}; // array 2 dimensi berukuran 8x8 dengan menginisialisasi semua elemennya dengan angka 0
    koboImaginaryChess(i, j, 8, (int *)chessBoard); // memanggil fungsi dan menambahkan argumen
    for(int x = 0; x < 8; x++){ // melakukan nested loop untuk mencetak seluruh nilai array dalam fungsi 
        for(int a = 0; a < 8; a++){
            printf("%d", chessBoard[x][a]);
        }
        printf("\n");
    }
    return 0;
}
