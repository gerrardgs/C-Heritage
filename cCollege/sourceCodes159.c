#include <stdio.h>
#include <string.h>

struct Buku 
{
    char pengarang[50];
    char judul[30];
    int tahun;
};

int main(){

    struct Buku buku[3]; 
    for (int i = 0; i < 3; i++)
    {
        printf("Pengisian Buku ke-%i \n", i + 1);
        printf("Masukkan Nama Pengarang : ");
        fflush(stdin);gets(buku[i].pengarang);
        printf("Masukkan Judul                     :");
        fflush(stdin);gets(buku[i].judul);
        printf("Masukkan Tahun : ");
        scanf("%i", &buku[i].tahun);    
        }

    printf("\nData yang telah dimasukkan adalah : \n");
    printf("---------------------------------------------\n");
    printf("| Pengarang | Judul | Tahun \n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < 3; i++)
    {
        printf("| %s | %s | %i | \n", buku[i].pengarang, buku[i].judul, buku[i].tahun);
    }
    printf("---------------------------------------------\n");
    
    return 0;}
