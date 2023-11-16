#include <stdio.h>

int main (void){
    int Array3[] = {10, 20, 30, 40}; // array 1 dimensi
    printf("\nNilai array 3 pada %i", Array3[2]);

    int iniArray[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};// array 2 dimensi
    printf("\nNilai array pada %i", iniArray[3][3]);

    char arr[3][10] = {"Hallo", "Welcome", "Semuanya"}; // array-string
    for (int i = 0; i < 3; i++)
    {
        printf("\n%s", arr[i]);
    }

    int x[5] = {6, 8, 10, 12, 15};
    printf("Nilai array x : ");
    for(int i = 0; i < 5; i++){
        printf("%i ,",x[i]);
    }
    int cari, new;
    printf("\nMasukkan elemen array yang ingin dirubah : ");
    scanf("%i", &cari);
    //misal 15
    printf("\nMasukkan nilai elemen yang baru : ");
    scanf("%i", &new);
    //misal 12
    for(int i = 0; i<5;  i ++){
        if(x[i]==cari){
            x[i]=new;
        }
    }
    printf("\nNilai array x yang telah di update adalah : ");
    for(int i = 0; i <5; i++){
        printf("%i ,",x[i]);
    }
}
