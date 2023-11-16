// NO. 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{ // mendeclare struct node beranggotakan name dengan total 100 bertipe char, prev bertipe pointer node dan next bertipe pointer node
    char name[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(const char* name){ // mendeclare fungsi baru berargumen const char yang disebut name, dan mengembalikan pointer ke struct node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // mengalokasikan memori menggunakan fungsi malloc dan sesuai dengan ukuran struct node
    strcpy(newNode->name, name); // mendeclare fungsi strcpy untuk menyalin name ke dalam anggota name dari newnode
    newNode->prev = NULL; // mendeclare pointer prev dari node baru menjadi NULL
    newNode->next = NULL; // mendeclare pointer next dari node baru menjadi NULL
    return newNode; // mengembalikan pointer ke node baru
}

void enqueue(struct Node** head, struct Node** tail, const char* name){ // mendeclare fungsi enqueue berargumen struct node head, struct node tail, dan const char name
    struct Node* newNode = createNode(name); // mendeclare pemanggil fungsi create node untuk membuat node baru
    if(*head == NULL){ // mendeclare sebuah kondisi jika head bernilai NULL maka newnode dianggap sebagai satu-satunya node dalam linked list
        *head = newNode; // head dan tail diatur agar merujuk ke newnode 
        *tail = newNode;
        return;
    }
    (*tail)->next = newNode; // menghubungkan next dari node yang berada di pointer tail dengan newnode 
    newNode->prev = *tail; // menghubungkan prev dari newnode dengan tail 
    *tail = newNode; // menghubungkan tail yang merujuk ke newnode
}

void dequeue(struct Node** head){ // mendeclare fungsi dequeue berargumen pointer pointer struct node head 
    if(*head == NULL){ // mendeclare sebuah kondisi apakah head bernilai NULL
        printf("Antrian kosong.\n"); // menampilkan output kepada user
        return;
    }
    struct Node* temp = *head; // mendeclare variabel temp dengan nilai yang ditunjuk oleh head. 
    *head = (*head)->next; // head merujuk ke node berikutnya yaitu head next sehingga node pertama dapat dihapus dari antrian
    if(*head != NULL){ // mendeclare sebuah kondisi apakah head tidak bernilai NULL 
        (*head)->prev = NULL; // jika kondisi terpenuhi maka prev dari head diatur menjadi NULL 
    }
    free(temp); // membebaskan (menghapus) memori temp yang dituju
}

void checkQueue(struct Node* head, const char* name){ // mendeclare fungsi checkQueue berargumen struct node head dan const char name
    if(head == NULL){ // mendeclare sebuah kondisi apakah head bernilai NULL
        printf("Antrian kosong.\n"); // jika kondisi terpenuhi, maka akan tampil output seperti berikut
        return;
    }

    struct Node* temp = head; // mendeclare variabel temp dan head 
    int count = 0; // mendeclare variabel count yang diatur dari 0 sebagai penghitung posisi node dalam antrian
    while(temp != NULL){ // mendeclare perulangan yang akan berjalan selama temp tidak bernilai NULL
        if(strcmp(temp->name, name) == 0){ // mendeclare kondisi apakah temp name adalah name 
            printf("Antrian atas nama %s kurang %d antrian lagi.\n", name, count); // jika kondisi terpenuhi, maka akan tampil output seperti berikut
            return;
        }
        temp = temp->next; // mengubah temp untuk merujuk kepada node berikutnya
        count++; // meningkatkan value count sebesar 1 agar jika perulangan berulang dan nama pada node tersebut tidak cocok, maka count akan bertambah 1
    }
    printf("Nama tidak ditemukan dalam antrian.\n"); // jika kondisi tidak terpenuhi, maka akan tampil output seperti berikut
}

void displayQueue(struct Node* head){ // mendeclare fungsi displayQueue berargumen struct node head 
    if(head == NULL){ // mendeclare kondisi apakah head bernilai null
        printf("Antrian kosong.\n"); // jika kondisi terpenuhi, maka akan tampil output seperti berikut
        return;
    }

    struct Node* temp = head; // mendeclare variabel temp dan head
    int position = 1; // mendeclare variabel position yang diatur dari 1 untuk mencari posisi node di antrian saat proses mencetak
    printf("Daftar Pasien dalam Antrian:\n"); // lalu menampilkan output kepada user seperti berikut
    while(temp != NULL){ // mendeclare perulangan while yang berjalan selama temp tidak bernilai NULL
        printf("[%d] Nama: %s\n", position, temp->name); // lalu menampilkan output ke user dengan menampilkan nomor posisi dan nama pasien 
        temp = temp->next; // mengubah temp untuk merujuk kepada node berikutnya
        position++; // meningkatkan value position sebesar 1 agar jika perulangan berulang dan nama pada node tersebut tidak cocok, maka position akan bertambah 1
    }
}

int main(){ // mendeclare fungsi main
    struct Node* head = NULL; // Mendeclare variabel head dan tail (pointer) ke struct node dan diinialisasi dengan NULL
    struct Node* tail = NULL;
    char name[100]; // mendeclare variabel name bertipe data char sebagai array karakter yang dapat berisikan maksimal 100 kata 
    int choice; // mendeclare variabel choice bertipe data int

    do{ // mendeclare perulangan pada menu 
        printf("\n------------ANTRIAN RUMAH SAKIT------------\n"); // menampilkan output kepada user dengan format berikut
        displayQueue(head); // mendeclare pemanggilan fungsi displayQueue untuk menampilkan antrian

        printf("\nMenu:\n"); // menampilkan output kepada user dengan format berikut
        printf("1. Tambah Antrian\n"); // menampilkan output kepada user dengan format berikut
        printf("2. Hapus Antrian\n"); // menampilkan output kepada user dengan format berikut
        printf("3. Cek Antrian\n"); // menampilkan output kepada user dengan format berikut
        printf("4. Exit\n"); // menampilkan output kepada user dengan format berikut
        printf("Pilihan: "); // menampilkan output kepada user dengan format berikut
        scanf("%d", &choice); // input dari user akan diterima menggunakan scanf

        switch(choice){ // mendeclare switch-case 
            case 1: // jika masuk dalam case 1, user memasukkan nama dan diterima menggunakan scanf, kemudian memanggil enqueue untuk menambahkan antrian
                printf("Masukkan Nama: ");
                scanf("%s", name);
                enqueue(&head, &tail, name);
                break;
            case 2: // jika masuk dalam case 2, memanggil dequeue untuk menghapus antrian
                dequeue(&head);
                break;
            case 3: // jika masuk dalam case 3, user memasukkan nama yang ingin dicek dan diterima menggunakan scanf, kemudian memanggil checkQueue untuk memeriksa
                printf("Masukkan Nama yang Ingin Dicek: ");
                scanf("%s", name);
                checkQueue(head, name);
                break;
            case 4: // jika masuk dalam case 4, akan tampil output dengan format berikut.
                printf("Keluar dari program.\n");
                break;
            default: // jiks pilihan user tidak valid, akan tampil output dengan format berikut.
                printf("Pilihan tidak valid.\n");
        }
    }
    while(choice != 4); // perulangan akan berlanjut selama pilihan tidak sama dengan 4, yaitu sampai user memilih menu exit
    while(head != NULL){ // perulangan dijalankan untuk menghapus sisa antrian yang mungkin masi ada didalam linked list
        dequeue(&head); // memanggil fungsi dequeue pada head sampai head bernilai NULL
    }
    return 0; // mengembalikan value tanda bahwa program selesai dijalankan 
}
