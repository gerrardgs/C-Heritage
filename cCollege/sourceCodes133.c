// NO. 4

// Declare library
#include <stdio.h>

int JumlahDigit(int n){ // fungsi jumlahdigit berargumen n bertipe data integer
    if(n < 10){ // kondisi recurse jika n kurang dari 10,
        return 1; // maka fungsi mengembalikkan nilai 1
    }
    else{ // jika tidak,
        return 1 + JumlahDigit(n / 10); // maka recurse pertama dipanggil dengan membagi n dan 10 untuk menghilangkan nilai terakhir dan ditambah 1.
    }
}

int main(){ // fungsi main
    int bilangan; // variabel bilangan bertipe data integer
    printf("Masukkan bilangan bulat: "); // menampilkan output kepada user
    scanf("%d", &bilangan); // membaca dan menyimpan input user dalam variabel bilangan
    int jumlahDigit = JumlahDigit(bilangan); // fungsi jumlahdigit dipanggil untuk menghitung variabel jumlahdigit dalam variabel bilangan dan hasilnya disimpan dalam variabel jumlahdigit
    printf("Jumlah digit: %d\n", jumlahDigit); // menampilkan output kepada user berupa jumlah digit yang ditemukan di bilangan, yang telah disimpan dalam variabel jumlahdigit
    return 0; // mengakhiri program, menunjukkan bahwa program telah selesai dijalankan tanpa kesalahan
}
