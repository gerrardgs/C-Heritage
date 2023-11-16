// NO. 3

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

void sortData(Node **node){ // fungsi sortData
    return; // fungsi selesai
  Node *current = *node; // pointer current merujuk ke node pertama 
  Node *temp = NULL; // variabel pointer temp dengan nilai Null
  int swapped; // variabel value bertipe int
  do{ // perulangan
    swapped = 0; // nilai swapped dimulai dari 0
    current = *node; // mengatur current ke node awal sebelum iterasi perulangan
    while(current->next != *node){ // perulangan berjalan selama current tidak mencapai node terakhir
      if(current->value > current->next->value){ // kondisi apakah nilai current lebih besar daripada nilai node sebelumya
        int tempValue = current->value; // menyimpan current->value ke variabel tempValue
        current->value = current->next->value; // memindahkan nilai dari node berikutnya ke node saat ini
        current->next->value = tempValue; // memindahkan nilai tempValue ke node berikutnya
        swapped = 1; // mengatur nilai swapped dari 1
      }
      current = current->next; // dari node saat ini pindah ke node berikutnya
    }
  }
  while (swapped); // perulangan berjalan selama swapped bernilai true
}

void showData(Node *node){ // fungsi showData
  if(node == NULL) // kondisi node kosong
    return; // fungsi selesai
  Node *current = node; // pointer current merujuk ke node pertama 
  do{ // perulangan 
    printf("Elemen %d ", current->value); // tampilan berupa value dari current node
    current = current->next; // memindahkan current ke node selanjutnya dengan pointer next
  }
  while(current != node); // memeriksa current telah kembali atau tidak ke node pertama.
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
  int numOfElements, elementValue; // variabel numOfValues dan elementValue
  printf("Masukkan jumlah elemen: "); // tampilan output bagi user
  scanf("%d", &numOfElements); // membaca input dan menyimpan dalam variabel numOfElements
  for(int i = 0; i < numOfElements; i++){ // perulangan numOfValues berjalan tergantung jumlah element yang diinput user
    printf("Elemen ke-%d: ", i + 1); // tampilan output bagi user
    scanf("%d", &elementValue); //// membaca input dan menyimpan dalam variabel elementValue
    insertNode(&node, elementValue); // memanggil fungsi insertNode untuk input elementValue ke node
  }
  printf("\nList sebelum diurutkan: "); // tampilan output bagi user
  showData(node); // memanggil fungsi showData untuk menampilkan isi node sebelum diurutkan
  sortData(&node); // memanggil fungsi sortData untuk mengurutkan isi node/elemen
  printf("List setelah diurutkan: "); // tampilan output bagi user
  showData(node); // memanggil fungsi showData untuk menampilkan isi node setelah diurutkan
  freeData(node); // memanggil fungsi freeData untuk membebasan pengalokasian memori bagi daftar elemen
  return 0; // mengembalikan nilai tanda program telah berjalan dengan baik
}
