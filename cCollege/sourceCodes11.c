#include <stdio.h>

int main() {
    char arr[] = "Nama Saya Joko Widodo"; // Menggunakan double quotes untuk string
    int arrLen = sizeof(arr) - 1; // Mengurangi 1 karena sizeof(arr) akan menyertakan null terminator '\0'
    int kata = 1; // Inisialisasi dengan 1 karena setiap kalimat memiliki minimal 1 kata

    for (int a = 0; a < arrLen; a++) {
        if (arr[a] == ' ') {
            kata++;
        }
    }

    printf("%d", kata);
    return 0; // Menambahkan return 0 karena main() berfungsi sebagai int
}
