#include <stdio.h>

int main() {
  int size = 5;
  int angka[] = {5, 7, 2, 9, 1};

  for (int a = 0; a < size - 1; a++)
  {
    for (int b = 0; b < size - a; b++)
    {
      if (angka[b] > angka[b+1])
      {
        int temp = angka[b];
        angka[b] = angka[b+1];
        angka[b+1] = temp;
      }   
    }    
  }
  for (int a = 0; a < size; a++)
  {
    printf("[%d] ", angka[a]);
  }
  printf("\n");
}
