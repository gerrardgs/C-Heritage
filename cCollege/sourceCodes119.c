#include <stdio.h>

int tambah(int a, int b)
{
   int hasil = a + b; 
   return hasil;
}

int main()
{
    int hasil = tambah(1, 2);
    printf("hasil = %d", hasil);
}
