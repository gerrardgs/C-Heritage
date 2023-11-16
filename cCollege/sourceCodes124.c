#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 10 // mendeclare ukuran maksimum data yang bisa diinputkan

typedef struct{ // mendeclare struct queue
  int data[MAX_DATA]; // mendeclare tiga elemen queue yaitu data, head, dan tail
  int head;
  int tail;
} Queue;

void init(Queue *q){// mendeclare variabel untuk menginisialisasi queue
  q->head = q->tail = -1;// mendeclare kondisi untuk mengatur nilai head dan tail yang menyatakan bahwa antrian kosong (-1)
}

int isEmpty(Queue *q){// mendeclare variabel untuk mengecek queue kosong atau tidak
  return q->head == -1 && q->tail == -1; // mendeclare sebuah kondisi jika nilai head dan tail sama-sama -1, maka antrian dianggap kosong dan fungsi ini mengembalikan nilai 1 (benar). Jika tidak, fungsi ini mengembalikan nilai 0 (salah).
}

int isFull(Queue *q){// mendeclare variabel untuk mengecek queue penuh atau tidak
  return q->tail == MAX_DATA - 1; // mendeclare jika nilai tail = maxdata - 1, maka antrian dianggap penuh dan fungsi ini mengembalikan nilai 1 (benar). Jika tidak, fungsi ini mengembalikan nilai 0 (salah).
}

// Mengembalikan jumlah elemen dalam antrian
int size(Queue *q){ // mendeclare sebuah size yang digunakan untuk mengembalikan jumlah elemen dalam antrian. Jika antrian kosong, fungsi ini mengembalikan nilai 0. Jika tidak, fungsi ini menghitung operasi (tail-head) + 1
  if (isEmpty(q))
    return 0;
  return q->tail - q->head + 1;
}

// Mengembalikan elemen di depan antrian, Jika antrian tidak kosong (isEmpty) maka fungsi ini mengembalikan nilai data diindex head. Jika antrian kosong, fungsi ini mengembalikan nilai -1.
int getHead(Queue *q){
  return !isEmpty(q) ? q->data[q->head] : -1;
}

// Mengembalikan elemen di belakang antrian. Jika antrian tidak kosong (isEmpty) maka fungsi ini mengembalikan nilai data diindex tail. ika antrian kosong, fungsi ini mengembalikan nilai -1.
int getTail(Queue *q){
  return !isEmpty(q) ? q->data[q->tail] : -1;
}

void enqueue(Queue *q, int value){// mendeclare enqueue untuk menambahkan data
  if(!isFull(q)){// kondisi/Fungsi ini melakukan pengecekan terlebih dahulu apakah antrian penuh. (isFull). Jika antrian tidak penuh, maka fungsi ini memeriksa apakah antrian awalnya kosong (isEmpty)
    if(isEmpty(q)){// jika ya maka head diincrementkan dan elemen pertama ditambahkan ke dalam data. Jika tidak maka tail diincrementkan dan elemen baru ditambahkan ke dalam data. Jika antrian penuh, maka akan tampil output "Antrian penuh".
      q->head++;
      q->data[++q->tail] = value;
      return;
    }
    q->data[++q->tail] = value;
    return;
  }
  printf("Antrian penuh\n");
}

void dequeue(Queue *q){// mendeclare dequeue untuk menghapus elemen dari antrian dan mengembalikkan karakter yang dihapus
  if(!isEmpty(q)){// mendeclare sebuah kondisi jika antrian tidak kosong, maka elemen pertama dihapus dengan menggeser elemen-elemen di belakangnya ke posisi sebelumnya.
    if(q->head == 0 && q->tail == 0){
      q->head--;
      q->tail--;
      return;
    }
    for (int i = q->head + 1; i < q->tail + 1; i++) // Setelah penghapusan elemen pertama, penunjuk head dan tail diubah
    {
      q->data[i - 1] = q->data[i];
    }
    q->tail--;
    return;
  }
  printf("Antrian kosong\n");// mendeclare sebuah statement jika antrian kosong, akan ditampilkan output berupa "Antrian kosong".
}

// Membandingkan dan memindahkan elemen dari antrian 1 ke antrian 2
void compareSwitch(Queue *q1, Queue *q2){// mendeclare sebuah fungsi. Fungsi ini digunakan untuk membandingkan dan memindahkan elemen dari antrian q1 ke q2
  int flag = 1;// Selama kedua antrian q1 dan q2 tidak kosong, fungsi akan membandingkan elemen pertama dari kedua antrian.
  while(!isEmpty(q1) && !isEmpty(q2) && flag){
    flag = 0;
    if (getHead(q1) == getHead(q2)){
      dequeue(q1); // mendeclare sebuah kondisi jika elemen pertama kedua antrian sama, maka elemen tersebut dihapus dari kedua antrian menggunakan fungsi dequeue.
      dequeue(q2);
    }
    else{// mendeclare sebuah kondisi Jika elemen pertama kedua antrian berbeda, maka elemen pertama dari q1 dihapus menggunakan fungsi dequeue dan kemudian dimasukkan kembali ke q1 menggunakan fungsi enqueue.
      int temp = getHead(q1);
      dequeue(q1);
      enqueue(q1, temp);
    }
    for(int i = 0; i < size(q1); i++){// mendeclare sebuah perulangan yang berfungsi akan memeriksa apakah elemen yang baru dimasukkan ke q1 juga ada di q2, dan jika ada, proses perbandingan dan penghapusan akan dilanjutkan.
      if(q1->data[i] == getHead(q2)){
        flag = 1;// program akan berhenti melakukan operasi lanjutan ketika salah satu dari kedua antrian kosong atau tidak ada lagi elemen yang dapat dibandingkan dan dipindahkan.
      }
    }
  }
}

int main(){ // mendeclare fungsi main
  Queue q1, q2; // menginisialisasi q1 dan q2
  init(&q1);
  init(&q2);
  int numOfData;
  printf("total data: "); // mendeclare sebuah output yang nantinya harus diisi oleh user, yaitu banyaknya data yang hendak dimasukkan (jumlah)
  scanf("%d", &numOfData);
  int student[numOfData];
  int bubur[numOfData];

  printf("student: ");// mendeclare sebuah output yang nantinya harus diisi oleh user, yaitu banyaknya data yang hendak dimasukkan (students)
  for(int i = 0; i < numOfData; i++){
    scanf("%d", &student[i]);
    enqueue(&q1, student[i]);// Setiap data yang dimasukkan akan ditambahkan ke antrian q1 dan q2 menggunakan fungsi enqueue().
  }

  printf("bubur: "); // mendeclare sebuah output yang nantinya harus diisi oleh user, yaitu banyaknya data yang hendak dimasukkan (bubur)
  for(int i = 0; i < numOfData; i++){
    scanf("%d", &bubur[i]);
    enqueue(&q2, bubur[i]);
  }
  compareSwitch(&q1, &q2);//Setelah itu, fungsi compareSwitch dipanggil untuk membandingkan dan memindahkan elemen dari kedua antrian.
  printf("%d\n", size(&q1));// mendeclare sebuah output yang berisi ukuran antrian q1 setelah proses perbandingan dan pemindahan ditampilkan menggunakan fungsi size().
}
