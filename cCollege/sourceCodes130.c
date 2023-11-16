// NO. 1

// Declare library
#include <stdio.h>
#include <string.h>

void Subsequences(char *str, int start, char *subseq){ // fungsi subsequences dengan 3 argumen yaitu pointer str, start bertipe data integer, dan pointer subseq
    int len = strlen(str); // fungsi strlen untuk menghitung panjang str dan menyimpan dalam variabel len
    if(start == len){ // kondisi jika start sama dengan len, maka subsequen yang ditemukan akan dicetak dalam bentuk output kepada user
        printf("\"%s\"\n", subseq);
        return; // mengembalikkan kontrol ke pemanggil
    }
    Subsequences(str, start + 1, subseq); // recurse pertama ke fungsi subsequences dengan nilai start ditambah 1 dan memproses karakter selanjutnya
    subseq[strlen(subseq)] = str[start]; // memasukkan karakter str[start] ke subseq dan strlen(subseq) sebagai penempatan karakter baru pada akhir subsequeces
    Subsequences(str, start + 1, subseq); // recurse kedua ke fungsi subsequences dengan nilai start ditambah 1 dan memproses karakter selanjutnya
    subseq[strlen(subseq) - 1] = '\0'; // menghapus karakter terakhir dari subsequences dengan mengatur karakter terakhir menjadi \0 atau NULL
}

int main(){ // fungsi main
    char str[100]; // array str berkapasitas 100
    printf("Masukkan string: "); // menampilkan output kepada user
    scanf("%s", str); // membaca dan menyimpan input user kedalam str 
    char subseq[100] = ""; // array subseq berkapasitas 100
    printf("Outputnya adalah:\n"); // menampilkan output kepada user
    Subsequences(str, 0, subseq); // memanggil fungsi subsequences berargumen str dengan input string '0' dan subseq sebagai subsequences awal yang kosong
    return 0; // mengakhiri program, menunjukkan bahwa program telah selesai dijalankan tanpa kesalahan
}
