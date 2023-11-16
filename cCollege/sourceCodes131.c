// NO. 2

// Declare library
#include <stdio.h>
#include <string.h>

int isitPalindrome(char str[], int start, int end){ // fungsi isitpalindrome berargumen array str, start bertipe data integer dan end bertipe data integer
    if(start == end){ // kondisi jika start sama dengan end,
        return 1; // maka fungsi dikembalikkan nilai 1 yang menunjukkan bahwa string tersebut bukan palindrome
    }
    if(str[start] != str[end]){ // jika karakter str[start] tidak sama dengan karakter str[end],
        return 0; // maka fungsi dikembalikkan nilai 0 yang menunjukkan bahwa string tersebut bukan palindrome
    }
    if(start < end + 1){ // kondisi recurse pertama dengan nilai start dan end untuk memeriksa substring diantara karakter start dan end dan akan terus berlanjut sampai semua karakter terperiksa 
        return isitPalindrome(str, start + 1, end - 1); // fungsi dikembalikan dengan catatan saat pemeriksaan, nilai start ditambah 1 dan nilai end dikurangi 1
    }
    return 1; // maka fungsi dikembalikkan nilai 1 yang menunjukkan bahwa string tersebut palindrome
}

int main(){ // fungsi main
    char str[100]; // array str berkapasitas 100
    printf("Masukkan sebuah string: "); // menampilkan output kepada user
    fgets(str, sizeof(str), stdin); // fungsi fgets untuk membaca input user dan menyimpan dalam str termasuk input newline dan memeriksa batas ukuran sizeof(str) 
    str[strcspn(str, "\n")] = '\0'; // menghapus newline yang diambil oleh fgets menggunakan strcspn, serta mencari indeks pertama dari newline dalam str dan menggantinya menjadi \0 atau NULL (menghapus newline)
    if(isitPalindrome(str, 0, strlen(str) - 1)){ // kondisi fungsi isitpalindrome, apakah str merupakan palindrome atau tidak. Jika iya, maka..
        printf("String tersebut adalah palindrom.\n"); // menampilkan output kepada user
    }
    else{ // Jika tidak, maka..
        printf("String tersebut bukan palindrom.\n"); // menampilkan output kepada user
    }
    return 0; // mengakhiri program, menunjukkan bahwa program telah selesai dijalankan tanpa kesalahan
}
