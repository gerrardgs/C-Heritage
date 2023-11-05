#include <stdio.h>

void outputNilai(int *arr, int panjang){
  for(int i = 0; i < panjang; i++){
	  printf("%d ", arr[i]);
  }
}
void ascending(int *arr, int panjang){
  for(int i = 0; i < panjang - 1; i++){
    int temp;
    for (int j = 0; j < panjang - 1 - i; j++){
      if(arr[j] > arr[j+1]){
          temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
      }
    }
  }
  printf("Ascending : ");
  outputNilai(arr, panjang);
}

void descending(int *arr, int panjang){
  for(int i = 0; i < panjang - 1; i++){
    int temp;
    for (int j = 0; j < panjang - 1 - i; j++){
      if(arr[j] < arr[j+1]){
          temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
      }
    }
  }
  printf("\nDescending : ");
  outputNilai(arr, panjang);
}

int main(){
  int N;
  printf("Masukkan Banyak banyak inputan angka :");
  scanf("%d", &N);

  int arrayInt[N];
  int panjang = sizeof(arrayInt)/sizeof(int);

  for (int i = 0; i < panjang; i++)
  {
    printf("Masukkan angka %d: ", i+1);
    scanf("%d", &arrayInt[i]);
  }

  ascending(arrayInt, panjang);
  descending(arrayInt, panjang);
  
}
