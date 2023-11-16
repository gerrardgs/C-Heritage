// NO. 2

// declare library
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ // struktur data Node
  struct Node *prev; // pointer previous
  int value; // variabel value bertipe int
  struct Node *next; // pointer next
}Node;

Node *createNode(int value){ // fungsi createNode 
  Node *newNode = (Node *)malloc(sizeof(Node)); // alokasi memori Node menggunakan malloc 
  newNode->value = value; // parameter value ke dalam value dari Node yang baru dibuat
  newNode->next = NULL; // pointer next dari Node baru menjadi NULL
  newNode->prev = NULL; // pointer previous dari Node baru menjadi NULL
  return newNode; // mengembalikkan pointer ke node baru
}

Node *insertNode(Node **node, int value){ // fungsi insertNode, pointer ke pointer node 
  Node *newNode = createNode(value); // memanggil fungsi createNode untuk membuat node baru
  if(*node == NULL){ // kondisi memeriksa apakah pointer node bernilai kosong
    newNode->next = newNode; // pointer next Node baru ke dirinya sendiri
    newNode->prev = newNode; // pointer previous Node baru ke dirinya sendiri
    *node = newNode; // pointer node ke Node baru
  }
  else{ // kondisi jika kondisi tidak bernilai kosong
    newNode->next = *node; // pointer next ke node pertama
    newNode->prev = (*node)->prev; // pointer previous newNode ke node sebelumnya
    (*node)->prev->next = newNode; // pointer next node sebelumnya dari node ke newNode
    (*node)->prev = newNode; // pointer previous dari node ke newNode
  }
  return newNode; // mengembalikkan pointer ke node baru
}

void reverseData(Node **node){ // fungsi reverseData
  if(*node == NULL) // kondisi memeriksa apakah pointer node bernilai kosong
    return; // fungsi selesai
  Node *current = *node; // pointer current merujuk ke node pertama 
  Node *tmp = NULL; // variabel pointer temp dengan nilai Null
  do{ // perulangan 
    tmp = current->prev; // menyimpan node dari current ke variabel tmp
    current->prev = current->next; // memindahkan pointer previous dari current ke node berikutnya
    current->next = tmp; // memindahkan pointer previous dari current ke node sebelumnya di variabel tmp
    current = current->prev; // memindahkan current ke node sebelumnya
  }
  while(current != *node); // memeriksa current telah kembali atau tidak ke node pertama.
  *node = tmp->prev; // mengubah head dari pointer node ke node sebelumnya (tail) setelah operasi pembalikan
}

void showData(Node *node){ // fungsi showData
  if(node == NULL) // kondisi node kosong
    return; // fungsi selesai
  Node *current = node; // pointer current merujuk ke node pertama 
  do{ // perulangan 
    printf("%d ", current->value); // tampilan berupa value dari current node
    current = current->next; // memindahkan current ke node selanjutnya dengan pointer next
  }
  while (current != node); // memeriksa current telah kembali atau tidak ke node pertama.
  printf("\n"); // Jika iya maka loop akan berhenti, jika tidak maka loop akan berlanjut
}

void freeData(Node *node){ // fungsi freeData
  if(node == NULL) // kondisi node kosong
    return; // fungsi selesai
  Node *current = node; // pointer current merujuk ke node pertama 
  Node *next = node->next; // variabel pointer next ke node berikutnya
  while(next != node){ // perulangan yang berlanjut selama next tidak sama dengan node 
    free(current); // menghapus current node 
    current = next; // memindahkan current ke node berikutnya yang dihapus
    next = next->next; // memindahkan next ke node berikutnya dari next
  }
  free(current); // menghapus current last node 
}

int main(){ // fungsi main
  Node *node = NULL; // variabel pointer node bernilai Null
  int numOfValues, elementValue; // variabel numOfValues dan elementValue
  printf("Masukkan banyaknya nilai: "); // tampilan output bagi user
  scanf("%d", &numOfValues); // membaca input dan menyimpan dalam variabel numOfValues
  printf("Masukkan elemen nilai: "); // tampilan output bagi user
  for(int i = 0; i < numOfValues; i++){ // perulangan numOfValues berjalan tergantung jumlah value yang diinput user
    scanf("%d", &elementValue); // membaca input dan menyimpan dalam variabel elementValue
    insertNode(&node, elementValue); // memanggil fungsi insertNode untuk input elementValue ke node
  }
  printf("Sebelum direverse:\n"); // tampilan output bagi user
  printf("List: "); // tampilan output bagi user
  showData(node); // memanggil fungsi showData untuk menampilkan isi node sebelum direverse
  reverseData(&node); // memanggil fungsi reverseData untuk mereverse node 
  printf("\nSetelah direverse:\n"); // tampilan output bagi user
  printf("List: "); // tampilan output bagi user
  showData(node); // memanggil fungsi showData untuk menampilkan isi node setelah direverse
  freeData(node); // memanggil fungsi freeData untuk membebaskan alokasi memori disetiap node
  return 0; // mengembalikan nilai tanda program telah berjalan dengan baik
}
