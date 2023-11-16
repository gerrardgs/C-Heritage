// NO. 2

// DECLARE LIBRARY
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ // declare struktur node beranggotakan vertices value dan pointer node ke next node
    int value;
    struct Node* next;
}Node;

Node* createNode(int value){ // declare fungsi createnode dengan nilai tertentu beranggotakan value 
    Node* newNode = (Node*)malloc(sizeof(Node)); // alokasi memori node baru
    newNode->value = value; // menginisialisasi value dengan nilai yang diberi
    newNode->next = NULL; // mengatur value node next menjadi NULL
    return newNode; // node baru dikembalikan
}

void addEdge(Node** graph, int source, int destination){ // declare fungsi addedge untuk menambah edge antara 2 vertices kedalam graf beranggotakan pointer ke array graph, source, dan destination
    Node* newNode = createNode(destination); // membuat node baru bervalue destination menggunakan fungsi createnode 
    newNode->next = graph[source]; // mengatur pointer next pada node baru menjadi node dalan index source
    graph[source] = newNode; // pointer index source dalam array graph diubah ke node baru 
}

void printForbIns(Node** graph, int numInts, int maxUnds){ // declare fungsi printforbins untuk mencetak value persimpangan yang harus dihindari karakter zoro
    int i, j; // beranggotakan pointer ke array graph, numints, maxunds, variabel i dan j
    for(i = 0; i < numInts; i++){ // perulangan. fungsi beriterasi dimulai dari 0 dan berakhir ketika value i kurang dari numints
        int count = 0; // variabel count yang diinisialisasi dari 0
        Node* temp = graph[i]; // declare pointer temp dan inisialisasi dengan node pertama di index graph i
        while(temp != NULL){ // perulangan. berlanjut selama value temp tidak sama dengan null. digunakan untuk menghitung dengan mengiterasi melalui index graph
            count++; // setiap node yang dilewati maka count akan bertambah 1
            temp = temp->next; // melanjutkan temp ke node berikutnya agar iterasi tetap berjalan
        }
        if(count > maxUnds){ // kondisi apakah count lebih besar daripada maxunds
            printf("Persimpangan %d\n", i); // jika iya maka akan tampil output dengan format berikut ke interface user
        }
    }
}

int main(){ // fungsi main
    int numInts, zoroAge; // variabel numints dan zoroage
    scanf("%d", &numInts); // membaca dan menyimpan input user ke variabel yang dituju
    scanf("%d", &zoroAge); // membaca dan menyimpan input user ke variabel yang dituju
    Node** graph = (Node**)malloc(numInts * sizeof(Node*)); // declare objek graph baru sebagai array pointer ke node, alokasi memori graph dengan fungsi malloc dan menghitung jumlah memori melalui operasi numints * sizeof ke node
    int i; // variabel i 
    for(i = 0; i < numInts; i++){ // perulangan inisialisasi tiap elemen dalam graph
        graph[i] = NULL; // mengatur tiap elemen graph menjadi NULL 
    }
    int source, destination; // variabel source dan destination
    scanf("%d %d", &source, &destination); // membaca dan menyimpan input user ke variabel yang dituju
    while(source != -1 && destination != -1){ // perulangan untuk membaca input edge graph source dan destination dan akan berhenti apabila input -1 -1 ditemukan
        addEdge(graph, source, destination); // tiap edge yang dibaca akan ditambahkan ke dalam graph dengan fungsi addedge 
        addEdge(graph, destination, source); // karena graph bersifat undirected, maka edge ditambahkan dengan 2 opsi (source ke destination atau destination ke source)
        scanf("%d %d", &source, &destination); // membaca dan menyimpan input user ke variabel yang dituju
    }
    printf("\n"); // menampilkan output dengan format berikut ke interface user
    printf("Persimpangan yang harus dihindari oleh Roronoa Zoro adalah:\n"); // menampilkan output dengan format berikut ke interface user
    printForbIns(graph, numInts, zoroAge); // panggil fungsi printforbins untuk mencetak persimpangan yang harus dihindari zoro
    for(i = 0; i < numInts; i++){ // perulangan iterasi melalui tiap elemen array graph
        Node* temp = graph[i]; // declare pointer temp dan inisialisasi dengan node terkait persimpangan (i)
        while(temp != NULL){ // perulangan berjalan selama value temp tidak sama dengan NULL
            Node* prev = temp; // pointer prev untuk menyimpan reference ke node saat ini
            temp = temp->next; // iterasi dan memperbarui temp ke node berikutnya 
            free(prev); // membebaskan alokasi memori prev
        }
    }
    free(graph); // membebaskan alokasi memori array graph
    return 0; // program selesai
}
