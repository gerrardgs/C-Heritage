// NO. 3

// Declare library
#include <stdio.h>

int NilaiTerbesar(int arr[], int n){ // fungsi nilai terbesar berargumen arr bertipe data int, dan n bertipe data int
    if(n == 1){ // kondisi recurse jika n adalah 1, maka arr hanya memiliki 1 elemen 
        return arr[0]; // mengembalikan nilai elemen sebagai nilai terbesar
    }
    int subMax = NilaiTerbesar(arr, n - 1); // recurse pertama untuk mencari nilai terbesar dalam subarr kecil. nilaiterbesar dipanggil arr dengan catatan n-1 
    if(arr[n - 1] > subMax){ // kondisi jika arr[n-1] lebih besar daripada subMax,
        return arr[n - 1]; // maka nilai terbesar array adalah arr[n-1]
    }
    else{ // Jika tidak,
        return subMax; // maka nilai terbesar array adalah submax
    }
}

int main(){ // fungsi main
    int n; // variabel integer n
    printf("Masukkan jumlah elemen dalam array: "); // menampilkan output kepada user
    scanf("%d", &n); // membaca dan menyimpan input user pada variabel n
    int arr[n]; // array n bertipe data integer 
    printf("Masukkan elemen-elemen array:\n"); // menampilkan output kepada user
    for(int i = 0; i < n; i++){ // perulangan for untuk membaca dan menyimpan input array user di arr dengan scanf
        scanf("%d", &arr[i]);
    }
    int max = NilaiTerbesar(arr, n); // fungsi nilaiterbesar dipanggil untuk mencari nilai terbesar arr dengan elemen n dan menyimpan dalam variabel max
    printf("Nilai terbesar dalam array adalah: %d\n", max); // menampilkan output kepada user dengan format nilai terbesar dalam array yang telah tersimpan dalam variabel max
    return 0; // mengakhiri program, menunjukkan bahwa program telah selesai dijalankan tanpa kesalahan
}
