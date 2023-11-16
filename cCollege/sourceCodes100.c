#include <stdio.h>

int perkalian(int, int);
void main()
{
    int bil1, bil2;
    puts("Menghitung perkalian dari 2 bilangan");
    printf("Masukkan bilangan pertama: ");
    scanf("%d", &bil1);
    printf("Masukkan bilangan kedua: ");
    scanf("%d", &bil2);
printf("Hasil perkalian %d dengan %d adalah: %d\n", bil1, bil2, perkalian(bil1, bil2));
getch();
}
int perkalian(int bilangan1, int bilangan2)
{
if(bilangan2==1)
return bilangan1;
else 
return bilangan1+perkalian(bilangan1,bilangan2-1);
}



void ascending(int n) {
    if (n == 0) {
        return;
    } else {
        ascending(n-1);
        printf("%d ", n);
    }
}
int main(){
    int n;
    printf("masukan n");
    scanf("%d",&n);
    ascending(n);
}



int Multiply(int x, int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return x;
    } else {
        return x + Multiply(x, n-1);
    }
}
int main(){
    int x,y;
   printf("masukan x:");
   scanf("%d",&x);
   printf("masukan y:");
   scanf("%d",&y);
 printf("hasil: %d",Multiply(x,y));
}
