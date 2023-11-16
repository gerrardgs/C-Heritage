// NO. 1

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100// mendeclare maks ukuran stack

int disk[MAX_SIZE];// mendeclare variabel disk dan top
int top = -1;

void push(int data){//mendeclare suatu fungsi push untuk menambahkan elemen ke stack
    if(top == MAX_SIZE - 1){// mendeclare suatu kondisi apabila stack sudah penuh, maka akan tampil output berupa "stact penuh"
        printf("Stact Penuh\n");
    } else{// mendeclare suatu kondisi untuk menambahkan elemen ke stack, dan menggeser posisi top
        top++;
        disk[top] = data;
    }
}

int pop(){// mendeclare suatu fungsi pop untuk mengambil elemen dari stack
    if(top == -1){// mendeclare suatu kondisi apabila stack kosong, maka akan tampil output berupa "stact kosong"
        printf("Stact Kosong\n");
        return -1;
    } else{// mendeclare suatu kondisi untuk mengambil elemen stack, dan menggeser posisi top
        int data = disk[top];
        top--;
        return data;
    }
}

void moveDisk(char from, char to, int disk){// mendeclare suatu fungsi untuk memindahkan disk dari satu tiang ke tiang lainnya
    printf("Pindahkan disk %d dari tiang '%c' ke tiang '%c'\n", disk, from, to);
}

void hanoi(int n, char source, char destination, char auxiliary){// mendeclare suatu fungsi rekursif untuk menyelesaikan permainan menara hanoi
    if(n == 1){// mendeclare suatu kondisi jika hanya ada 1 disk, maka akan langsung dipindahkan ke tujuan 
        moveDisk(source, destination, 1);
        return;
    }

    hanoi(n - 1, source, auxiliary, destination);// memindahkan n-1 disk dari tiang sumber ke tiang bantu
    moveDisk(source, destination, n);// memindahkan disk ke-n dari tiang sumber ke tujuan
    hanoi(n - 1, auxiliary, destination, source);// Pindahkan n-1 disk dari tiang bantu ke tujuan
}

int main(){// mendeclare fungsi main untuk memproses input dari code yang telah dibuat dan menampilkan output kepada user sesuai dengan apa yang hendak diketahui user
    int n, i;

    printf("Masukkan Jumlah Disk: ");// mendeclare suatu command dan menampilkan kepada user untuk memasukkan jumlah disk
    scanf("%d", &n);

    for(i = n; i >= 1; i--){// mendeclare variabel yang berfungsi untuk menambahkan disk pada stack, tetapi dengan urutan terbalik
        push(i);
    }

    hanoi(n, 'S', 'D', 'A');// mendeclare fungsi hanoi untuk menyelesaikan permainan dari input yang telah dimasukkan oleh user sebelumnya
    return 0;// mendeclare suatu variabel untuk Mengembalikan nilai 0 dan sebagai penanda bahwa program berjalan dengan sukses
}
