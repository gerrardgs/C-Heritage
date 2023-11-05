#include <stdio.h>

void bubbleSort(int *arr)
{
   for(int i = 0; i < 5 - 1; i++)
   {
      int temp;
      for (int j = 0; j < 5 - i; j++)
      {
	      if(arr[j] > arr[j+1])
        {
	        temp = arr[j];
	        arr[j] = arr[j+1];
	        arr[j+1] = temp;
	      }
      }
   }
}

void arrayAwal(int *arr)
{
   for(int i = 0; i < 5; i++)
   {
      printf("%d ", arr[i]);
   }
}


int main() {
   int x[5] = {15, 21, 4, 6, 2};
   printf ("Array awal : \n");
   arrayAwal(x);
   bubbleSort(x);
   printf("\nArray yang telah diurutkan : \n");
   arrayAwal(x);
	
   return (0);
}
