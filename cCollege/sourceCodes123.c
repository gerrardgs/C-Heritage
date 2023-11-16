// NO. 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // mendeclare ukuran data yg dapat disimpan

typedef struct{ // mendeclare struct queue
    char character;
    int count;
} CharacterCount;//

typedef struct{// mendeclare struct queue
    CharacterCount data[MAX_SIZE];// mendeclare variabel dan tipe data untuk menyimpan data dari queue
    int front;
    int rear;
} Queue; // mendeclare tipe data front untuk menyimpan index awal, rear untuk menyimpan index akhir.

void initializeQueue(Queue *queue){ // mendeclare variabel untuk menginisialisasi queue
    queue->front = -1;// declare queue front dan rear ke -1 untuk menandakan bahwa queue kosong
    queue->rear = -1;
}

int isQueueEmpty(Queue *queue){// mendeclare variabel untuk mengecek queue kosong atau tidak
    return (queue->front == -1 && queue->rear == -1);// mendeclare operasi jika front dan rear = -1, maka queue kosong
}

int isQueueFull(Queue *queue){// mendeclare variabel untuk mengecek queue penuh atau tidak
    return (queue->rear + 1) % MAX_SIZE == queue->front;// mendeclare operasi jika rear + 1 % size = front, maka queue penuh
}

void enqueue(Queue *queue, char character){// mendeclare enqueue untuk menambahkan data
    if(isQueueFull(queue)){//mendeclare sebuah fungsi jika queue penuh, maka akan tampil output "queue penuh"
        printf("Queue Penuh.\n");
        return;
    }

    if(isQueueEmpty(queue)){//mendeclare sebuah fungsi jika queue kosong, maka..
        queue->front = 0;// set front dan rear dari 0
        queue->rear = 0;
    } else{
        queue->rear = (queue->rear + 1) % MAX_SIZE;// jika ada maka rear + 1 % max size
    }// menambahkan elemen baru di posisi rear dan jika sudah mencapai max, maka akan kembali ke 0 

    queue->data[queue->rear].character = character;// mendeclare penambahan "character" dalam posisi antrian
    queue->data[queue->rear].count = 1;//mendeclare settingan count yg diatur menjadi 1 (agar karakter tersebut hanya muncul 1x)
}

char dequeue(Queue *queue){// mendeclare dequeue untuk menghapus elemen dari antrian dan mengembalikkan karakter yang dihapus
    if(isQueueEmpty(queue)){// mendeclare sebuah kondisi jika antrian kosong, maka akan tampil output "queue kosong"
        printf("Queue Kosong.\n");
        return '\0';
    }

    char dequeuedCharacter = queue->data[queue->front].character;//mendeclare karakter yang dihapus diambil diposisi front antrian

    if(queue->front == queue->rear){// mendeclare sebuah kondisi jika front = rear, maka antrian kosong dan akan diatur ke -1 sebagai penanda
        queue->front = -1;// jika front != rear, maka akan dilakukan operasi front +1 % max size. bertujuan untuk memajukan posisi front ke elemen antrian berikutnya
        queue->rear = -1;
    } else{
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return dequeuedCharacter;// mendeclare return dari karakter yang telah dihapus
}

int findFirstSingleCharacterIndex(char *string){// mendeclare variabel berparameter char *string
    int charCount[26] = {0};// mendeclare array dengan 26 ukuran dengan tujuan menyimpan semua kemunculan setiap karakter

    Queue queue;// mendeclare objek dan antrian yang akan diinisialisasikan dengan memanggil fungsi
    initializeQueue(&queue);// mendeclare fungsi untuk mengatur nilai front dan rear menjadi kosong (-1)

    for(int i = 0; i < strlen(string); i++){// mendeclare perulangan yang bertujuan untuk mengincrementkan setiap karakter string diindex yang sesuai dan nilai pada array "charcount"
        charCount[string[i] - 'a']++;
    }

    for(int i = 0; i < strlen(string); i++){// mendeclare perulangan yang bertujuan untuk dilakukan pengecekan apakah jumlah kemunculan karakter "charcount" pada indeks yang sesuai dengan karakter string adalah 1 dan jika iya, maka karakter tersebut akan dimasukkan ke dalam antrian menggunakan fungsi enqueue (&enqueue, string[i])
        if(charCount[string[i] - 'a'] == 1){
            enqueue(&queue, string[i]);
        }
    }

    for(int i = 0; i < strlen(string); i++){// mendeclare perulangan yang bertujuan untuk pengecekan apakah jumlah kemunculan karakter 'charcount' pada indeks yang sesuai dengan karakter string adalah 1 dan karakter pada string sama dengan karakter yang di dequeue dari antrian menggunakan fungsi dequeue(&queue)
        if(charCount[string[i] - 'a'] == 1 && string[i] == dequeue(&queue)){// 
            return i;// jika kedua kondisi tersebut terpenuhi, maka indeks akan dikembalikan sebagai hasil dari fungsi sekaligus menandakan bahwa karakter pertama yang muncul sekali ditemukan.
        }
    }
    return -1;// mendeclare return jika tidak ada karakter tunggal yang ditemukan, maka tidak ada karakter tunggal dalam string tersebut.(-1)
}

int main(){// mendeclare fungsi main
    char string[MAX_SIZE];// mendeclare sebuah string berukuran 
    scanf("%s", string);// mendeclare output yang nantinya dimasukkan user
    int index = findFirstSingleCharacterIndex(string);// mendeclare fungsi tersebut untuk memanggil dengan string sebagai argumen
    printf("%d\n", index);// index yang telah disimpan dalam fungsi sebelumnya akan keluar sebagai output
    return 0; // mendeclare return sebagai penanda bahwa program berhasil/telah selesai dijalankan user
}
