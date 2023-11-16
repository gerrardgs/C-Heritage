// Buat sebuah output berupa semua 
#include <stdio.h>

void printArr(int *arr, int n){

    for (int i = 0; i < n; i++){
        printf("%d ", *(arr + i));
    }
}

int main(){
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    printArr(arr,7);
}
