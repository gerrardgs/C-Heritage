// NO. 3

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

void push(struct Node** top, int data){ // mendeclare fungsi push untuk menambahkan elemen baru ke bagian atas stack dan mengambil argumen struct node top dan int data
    struct Node* newNode = createNode(data); // mendeclare fungsi baru untuk membuat node baru dengan memanggil fungsi createNode
    if(*top == NULL){ // mendeclare kondisi apakah top adalah NULL, maka stack bernilai kosong
        *top = newNode; // newNode dideclare sebagai elemen teratas dari stack dengan mengubah top ke newNode
        return;
    }
    newNode->next = *top; // jika stack tidak bernilai kosong, newNode next top akan membuat pointer next dari newNode ke elemen teratas dari stack
    (*top)->prev = newNode; // sementara itu top prev newNode membuat pointer prev dari elemen teratas dari stack ke newNode
    *top = newNode; // juga memastikan bahwa adanya hubungan dua arah antara elemen teratas dari stack dengan newNode
}

void pop(struct Node** top){ // mendeclare fungsi pop untuk menghapus elemen teratas dari stack dan berargumen struct Node top 
    if(*top == NULL){ // mendeclare kondisi apakah top adalah NULL, maka stack bernilai kosong
        printf("Stack kosong.\n"); // sementara itu akan tampil output dengan format berikut
        return;
    }
    struct Node* temp = *top; // jika stack tidak bernilai kosong, baris struct Node temp top akan membuat pointer temp yang merujuk pada elemen teratas dari stack
    *top = (*top)->next; // mengubah nilai top untuk mengarahkan ke elemen berikutnya pada stack dan akan menghapus elemen teratas dari stack
    if(*top != NULL){ // mendeclare kondisi apakah top bukan NULL, maka pointer prev dari elemen teratas tersebut diatur menjadi NULL 
        (*top)->prev = NULL;
    }
    free(temp); // membebaskan (menghapus) memori temp yang dituju
}

void printStack(struct Node* top){ // mendeclare fungsi printStack untuk mencetak isi stack, berargumen struct Node top 
    struct Node* temp = top; // membuat pointer temp yang merujuk pada elemen teratas dari stack
    while(temp != NULL){ // mendeclare perulangan while selama temp bukan merupakan NULL
        printf("%d ", temp->data); // di setiap proses perulangan, nilai dari elemen temp data ditampilkan kepada user 
        temp = temp->next; // memindahkan temp kepada elemen berikutnya dari stack
    }
    printf("\n");
}

void reverseStack(struct Node** top){ // mendeclare fungsi reverseStack untuk mengembalikan urutan elemen dalam stack, berargumen struct Node top
    struct Node* current = *top; // membuat pointer current yang akan merujuk kepada elemen teratas dari stack
    struct Node* prev = NULL; // membuat pointer prev yang berawalan NULL
    struct Node* next = NULL; // membuat pointer next yang berawalan NULL
    while(current != NULL){ // mendeclare perulangan while selama current bukan merupakan NULL
        next = current->next; // mendeclare penyimpanan referensi ke elemen berikutnya dari current
        current->next = prev; // mendeclare perubah pointer next dari current ke elemen prev
        current->prev = next; // mendeclare perubah pointer prev dari current ke elemen next
        prev = current; // mendeclare pengupdate prev yang merujuk ke current 
        current = next; // mendeclare pemindah current ke elemen berikutnya dari urutan asli stack
    }
    *top = prev; // mendeclare pengubah nilai top untuk merujuk ke elemen teratas yang baru 
}

int main(){ // mendeclare fungsi main
    struct Node* top = NULL; // mendeclare variabel top ke elemen teratas dari stack sehingga top diatur dari NULL
    int data; // mendeclare variabel data bertipe data int
    int choice; // mendeclare variabel choice bertipe data int

    do{ // mendeclare perulangan pada menu 
        printf("Masukkan Nilai: "); // menampilkan output kepada user dengan format berikut
        scanf("%d", &data); // input user diterima 
        push(&top, data); // input user yang sudah diterima, dimasukkan ke dalam stack menggunakan fungsi push yang akan menambahkan nilai baru dalam stack

        printf("Tambah Nilai Lagi? 999 = Exit : "); // menampilkan output kepada user dengan format berikut
        scanf("%d", &choice); // input user diterima 
    }
    while(choice != 999); // keterangan bahwa perulangan akan terus berulang selama nilai choice tidak sama dengan 999

    printf("\nStack Sebelum di Reverse: "); // menampilkan output kepada user dengan format berikut
    printStack(top); // memanggil fungsi printStack untuk mencetak isi dari stack sebelum dibalik

    reverseStack(&top); // memanggil fungsi reverseStack untuk membalik urutan elemen dari stack

    printf("\nStack Setelah di Reverse: "); // menampilkan output kepada user dengan format berikut
    printStack(top); // memanggil fungsi printStack untuk mencetak isi dari stack sebelum dibalik

    while(top != NULL){ // mendeclare perulangan while untuk mengosongkan stack 
        pop(&top); // memanggil fungsi pop untuk menghapus elemen teratas dari stack sampai stack bernilai kosong
    }
    return 0; // mengembalikan value tanda bahwa program selesai dijalankan 
}
