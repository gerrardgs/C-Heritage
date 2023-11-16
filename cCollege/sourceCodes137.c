// No. 2
#include <stdio.h>

typedef struct Pecahan{ // struct dengan 2 variabel, yaitu pembilang dan penyebut
    int pembilang;
    int penyebut;
} pecahan;

int gcd(int a, int b){ // mendeclare fungsi gcd yang nantinya akan menghitung nilai fpb antara dua bilangan bulat a dan b dengan menggunakan permisalan
    if (b == 0) { // jika b = 0, maka a merupakan fpb. jika tidak maka a % b dijadikan 2 parameter a dan b dalam memanggil fungsi
        return a;
    } else {
        return gcd(b, a % b);
    }
}

pecahan sederhanakan_pecahan(pecahan p){ // mendeclare fungsi sederhanakan_pecahan dengan parameter pecahan. fungsi ini berfungsi untuk memanggil fungsi gcd untuk
    int fpb = gcd(p.pembilang, p.penyebut); // mencari dan menemukan fpb antara pembilang dan penyebut pada pecahan. Juga mengembalikan pecahan ke yg paling sederhana
    pecahan hasil; // dengan membagi pecahan dengan fpb yang telah didapat sebelumnya. fpb sendiri adalah faktor persekutuan terbesar
    hasil.pembilang = p.pembilang / fpb;
    hasil.penyebut = p.penyebut / fpb;
    return hasil;
}

int main(){
    pecahan p1, p2, p3; // mendeclare fungsi dengan 3 variabel bertipe pecahan
    
    printf("(pembilang, penyebut): "); // mendeclare output bagi user, nantinya user akan memasukkan 3 buah pecahan secara berurutan
    scanf("%d %d", &p1.pembilang, &p1.penyebut); // yg diisi dgn pembilang dan penyebut. lalu memanggil fungsi sederhanakan_pecahan untuk pecahan yang sudah diinput user
    p1 = sederhanakan_pecahan(p1); // setelah data yang dimasukkan selesai diproses, akan keluar output berupa hasil pecahan sederhana dari yang sudah diinputkan user sebelumnya
    
    printf("(pembilang, penyebut): ");
    scanf("%d %d", &p2.pembilang, &p2.penyebut);
    p2 = sederhanakan_pecahan(p2);
    
    printf("(pembilang, penyebut): ");
    scanf("%d %d", &p3.pembilang, &p3.penyebut);
    p3 = sederhanakan_pecahan(p3);

    printf("%d/%d\n", p1.pembilang, p1.penyebut);
    printf("%d/%d\n", p2.pembilang, p2.penyebut);
    printf("%d/%d\n", p3.pembilang, p3.penyebut);
    
    return 0; // declare - mengembalikkan nilai dari program menjadi 0
}
