// NO. 1

// declare library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{ // struktur data Node
  struct Node *prev; // pointer previous
  int value; // variabel value bertipe int
  struct Node *next; // pointer next
}Node;

Node *createNode(int value){ // fungsi createNode 
  Node *newNode = (Node *)malloc(sizeof(Node)); // alokasi memori Node menggunakan malloc 
  newNode->value = value; // parameter value ke dalam value dari Node yang baru dibuat
  newNode->prev = NULL; // pointer previous dari Node baru menjadi NULL
  newNode->next = NULL; // pointer next dari Node baru menjadi NULL
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
    Node *tail = (*node)->prev; // pointer tail ke previous node 
    newNode->next = *node; // pointer next ke node pertama
    newNode->prev = tail; // pointer previous ke node terakhir
    tail->next = newNode; // pointer next dari node terakhir ke Node baru
    (*node)->prev = newNode; // pointer previous node pertama ke Node baru
  }
  return newNode; // mengembalikkan pointer ke node baru
}

void showData(Node *node){ // fungsi showData
  if(node == NULL){ // kondisi node kosong
    printf("Data Kosong.\n"); // tampilan output seperti format berikut
    return; // fungsi selesai
  }
  Node *current = node; // pointer current merujuk ke node pertama 
  do{ // perulangan 
    printf("%d ", current->value); // tampilan berupa value dari current node
    current = current->next; // memindahkan current ke node selanjutnya dengan pointer next
  }
  while(current != node); // memeriksa current telah kembali atau tidak ke node pertama.
  printf("\n"); // Jika iya maka loop akan berhenti, jika tidak maka loop akan berlanjut
}

void shuffleData(Node **node){ // fungsi shuffleData
  if(*node == NULL){ // kondisi node kosong
    return; // fungsi selesai
  }
  int count = 0; // variabel count dengan nilai 0
  Node *current = *node; // pointer current merujuk ke node pertama 
  do{ // perulangan 
    count++; // menaikkan nilai count setiap iterasi perulangan
    current = current->next; // memindahkan current ke node selanjutnya dengan pointer next
  }
  while (current != *node); // memeriksa current telah kembali atau tidak ke node pertama.
  srand(time(NULL)); // program pengacak bilangan menggunakan current time sebagai seed
  for(int i = count - 1; i > 0; i--){ // perulangan dengan count
    int j = rand() % (i + 1); // bilangan acak dengan fungsi rand
    Node *nodeI = *node; // 2 pointer dibuat ke node pertama
    Node *nodeJ = *node;
    while(i > 0){ // memindahkan pointer I dan j ke node di indeks i dan j
      nodeI = nodeI->next; // 
      i--;
    }
    while(j > 0){
      nodeJ = nodeJ->next;
      j--;
    }
    int tmp = nodeI->value; // menyimpan value dari node I ke variabel tmp
    nodeI->value = nodeJ->value; // mengganti value dari node I ke value dari node J
    nodeJ->value = tmp; // mengganti value dari node J ke variabel tmp
  }
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
  printf("Sebelum diacak: "); // tampilan output bagi user
  showData(node); // memanggil fungsi showData untuk menampilkan isi node sebelum diacak
  shuffleData(&node); // memanggil fungsi shuffleData untuk menampilkan isi node setelah diacak
  printf("Setelah diacak: "); // tampilan output bagi user
  showData(node);// memanggil fungsi showData untuk menampilkan isi node setelah diacak
  return 0; // mengembalikan nilai tanda program telah berjalan dengan baik
}
