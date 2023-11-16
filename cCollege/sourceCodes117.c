// NO. 1

#include <stdio.h>
#include <stdlib.h>

struct Node{ // mendeclare struktur node beranggotakan data bertipe int, prev bertipe pointer node dan next bertipe pointer node
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data){ // mendeclare fungsi create node yang mengambil data bertipe int dan pointer dikembalikan ke struct node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // mengalokasikan memori menggunakan fungsi malloc dan sesuai dengan ukuran struct node
    newNode->data = data; // mendeclare nilai data yang diberikan ke data lain dari node baru
    newNode->prev = NULL; // mendeclare pointer prev dari node baru menjadi NULL
    newNode->next = NULL; // mendeclare pointer next dari node baru menjadi NULL
    return newNode; // mengembalikan pointer ke node baru
}

void insertAtBeginning(struct Node** head, int data){ // mendeclare fungsi insertAtBeginning berargumen head bertipe struct node dan data bertipe int
    struct Node* newNode = createNode(data); // mendeclare pembuatan node baru dengan memanggil fungsi create node dan menyimpan dalam variabel newnode
    if(*head == NULL){ // mendeclare fungsi untuk memeriksa apakah head adalah null
        *head = newNode; // jika masih bernilai NULL, maka head akan diatur sebagai pointer ke newnode dan fungsi diakhiri dengan return
        return; 
    }
    newNode->next = *head; // jika tidak NULL, maka pointer next dari newnode akan merujuk ke head
    (*head)->prev = newNode; // pointer prev dari node pertama yang berisikan head diatur untuk merujuk head
    *head = newNode; // head diatur sebagai pointer ke newnode sehingga node baru menjadi node pertama
}

void insertAtEnd(struct Node** head, int data){ // mendeclare fungsi insertAtEnd berargumen head bertipe struct node, dan data bertipe int
    struct Node* newNode = createNode(data); // mendeclare pembuatan node baru dengan memanggil fungsi create node dan menyimpan dalam variabel newnode
    if(*head == NULL){ // mendeclare fungsi untuk memeriksa apakah head adalah null
        *head = newNode; // jika masih bernilai NULL, maka head akan diatur sebagai pointer ke newnode dan fungsi diakhiri dengan return
        return;
    }
    struct Node* temp = *head; // mendeclare pembuatan pointer temp yang merujuk ke head 
    while(temp->next != NULL){ // mendeclare perulangan while untuk mengiterasi linked list melalui temp next sampai temp next menjadi NULL 
        temp = temp->next; // memindah temp ke node berikutnya
    }
    temp->next = newNode; // menghubungkan newnode ke next dari temp
    newNode->prev = temp; // menghubungkan temp ke prev dari newnode 
}

void displayLIFO(struct Node* head){ // mendeclare fungsi displayLIFO berargumen head bertipe pointer struct node 
    struct Node* temp = head; // mendeclare pembuatan pointer temp yang merujuk ke head
    printf("Data Bilangan yang Telah Diinputkan secara FIFO:\n"); // menampilkan output kepada user
    while(temp != NULL){ // mendeclare perulangan while untuk mencetak data dari setiap node dengan iterasi melalui temp hingga temp menjadi NULL
        printf("%d\n", temp->data); // mencetak nilai data dari temp
        temp = temp->next; // memindah temp ke node berikutnya
    }
    printf("\n"); // menampilkan baris kosong setelah semua data dicetak
}

void displayFIFO(struct Node* head){ // mendeclare fungsi displayFIFO berargumen head bertipe pointer struct node 
    struct Node* temp = head; // mendeclare pembuatan pointer temp yang merujuk ke head
    printf("Data Bilangan yang Telah Diinputkan secara LIFO:\n"); // menampilkan output kepada user
    while(temp->next != NULL){ // mendeclare perulangan while dengan iterasi temp next hingga temp next menjadi NULL
        temp = temp->next; // memindah temp ke node berikutnya
    }
    while(temp != NULL){ // mendeclare perulangan while dengan iterasi melalui temp hingga temp menjadi NULL
        printf("%d\n", temp->data); // mencetak nilai data dari temp
        temp = temp->prev; // memindahkan temp ke node sebelumnya
    }
    printf("\n"); // menampilkan baris kosong setelah semua data dicetak
}

int main(){ // mendeclare fungsi main
    struct Node* head = NULL; // mendeclare variabel pointer head ke struct node bernilai NULL
    int data; // mendeclare variabel data dan choice
    char choice;

    do{ // mendeclare perulangan do-while agar input dapat tersimpan dan menyisipkan ke linked list menggunakan fungsi insertAtEnd. user akan terus menginputkan sampai tidak ada lagi data user yang diinputkan (pilihan y atau Y)
        printf("Masukkan bilangan: "); // menampilkan output kepada user
        scanf("%d", &data); // membaca input user dan memasukkannya kedalam variabel data
        insertAtEnd(&head, data); // mendeclare pemanggilan fungsi insertAtEnd untuk menyisipkan bilangan dengan menggunakan alamat argumen head dan data

        printf("Ada data lagi(y/t): "); // menampilkan output kepada user
        scanf(" %c", &choice); // membaca input user dan memasukkannya kedalam variabel choice
    }
    while(choice == 'y' || choice == 'Y'); // melakukan perulangan selama pilihan user adalah y atau Y dan user dapat memasukkan banyak data, tergantung kemauan user
    displayFIFO(head); // mendeclare pemanggilan fungsi displayFIFO untuk mencetak data dalam linked list secara FIFO
    displayLIFO(head); // mendeclare pemanggilan fungsi displayLIFO untuk mencetak data dalam linked list secara LIFO
    return 0; // mengembalikan value tanda bahwa program selesai dijalankan 
}
