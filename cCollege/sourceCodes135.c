// NO. 2

#include <stdio.h>
#include <string.h>

// mendeclare maks ukuran stack
#define max_size 100

// mendeclare array untuk mensave stack dan variabel top
char data[max_size];
int top = -1;

// mendeclare fungsi sebagai penambah elemen di stack 
void push(char x){
    // mendeclare suatu kondisi jika stack penuh, maka program menampilkan pesan "Stack Penuh"
    if(top == max_size - 1){
        printf("Stack Penuh\n");
    } 
    // mendeclare suatu kondisi jika masih ada ruang di stack, maka program menambahkan elemen ke dalam stack
    else{
        top++;
        data[top] = x;
    }
}

// mendeclare fungsi sebagai pendelete elemen di stack 
char pop(){
    // mendeclare suatu kondisi jika stack kosong, maka program menampilkan pesan "Stack kosong" dan kembalikan -1
    if(top == -1){
        printf("Stack kosong\n");
        return -1;
    } 
    // mendeclare suatu kondisi jika masih ada elemen di stack, maka program mengambil elemen teratas dan mengurangi nilai top
    else{
        char x = data[top];
        top--;
        return x;
    }
}

// mendeclare fungsi main
int main(){
    // mendeclare array untuk menyimpan inputan kalimat user
    char kalimat[max_size];
    // Mendeclare variabel untuk menyimpan panjang kalimat dan flag palindrom
    int i, panjang;
    int palindrom = 1;
    
    // meminta inputan kalimat dari user
    printf("Input : ");
    gets(kalimat);
    
    // mendeclare operasi untuk Menghitung panjang kalimat
    panjang = strlen(kalimat);

    // mendeclare suatu fungsi untuk Memasukkan karakter-karakter pada kalimat ke dalam stack
    for(i = 0; i < panjang; i++){
        // Jika karakter adalah huruf besar, ubah menjadi huruf kecil
        if(kalimat[i] >= 'A' && kalimat[i] <= 'Z'){
            kalimat[i] = kalimat[i] + ('a' - 'A');
        }
        // mendeclare suatu kondisi jika karakter bukan spasi, maka program akan memasukkannya ke dalam stack
        if(kalimat[i] != ' '){
            push(kalimat[i]);
        }
    }

    // mendeclare suatu fungsi untuk Membandingkan karakter-karakter pada kalimat untuk menentukan apakah kalimat tersebut merupakan palindrom atau tidak
    for(i = 0; i < panjang / 2; i++){
        // mendeclare suatu kondisi jika karakter pada kalimat tidak sama dengan karakter pada stack, maka program akan memproses dengan set flag palindrom yang menjadi 0 dan keluar dari loop
        if(kalimat[i] != pop()){
            palindrom = 0;
            break;
        }
    }

    // mendeclare suatu kondisi untuk Menampilkan output berdasarkan hasil pengecekan palindrom
    if(palindrom){
        printf("Output : Kata %s merupakan kata palindrom.\n", kalimat);
    } else{
        printf("Output : Kata %s bukan merupakan kata palindrom.\n", kalimat);
    }
    // mendeclare suatu variabel untuk Mengembalikan nilai 0 dan sebagai penanda bahwa program berjalan dengan sukses
    return 0;
}
