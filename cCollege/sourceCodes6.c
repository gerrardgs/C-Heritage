#include <stdio.h>
#include <stdlib.h>

struct mahasiswa{
char nama[30];
int mate;
int indo;
int ingg;
int keju;
float rata;
};


// void cariMahasiswa(int length, struct mahasiswa maha[20]){
//     system("cls");
//     for ( i = 0; i < count; i++)
//     {
//         /* code */
//     }
    
// }

void masukan (int length,struct mahasiswa maha[20]){


    system("cls");

    for(int i=0;i<length;i++){
    puts("========================");
    puts("  Input Mahasiswa Baru  ");
    puts("========================");
        printf("Masukkan Nama Mahasiswa ke-%i: ",i+1);
        scanf("%s",&maha[i].nama);
        printf("masukkan Nilai Matematika : ");
        scanf("%i",&maha[i].mate);
        printf("masukkan Nilai Bahasa Indonesia : ");
        scanf("%i",&maha[i].indo);
        printf("masukkan Nilai Bahasa Inggris : ");
        scanf("%i",&maha[i].ingg);
        printf("masukkan Nilai Kejuruhan : ");
        scanf("%i",&maha[i].keju);
        maha[i].rata=(maha[i].mate+maha[i].ingg+maha[i].indo+maha[i].keju)/4;
        system("cls");
    }
}

void rekap(int length,struct mahasiswa maha[20]){
 float rata;
 system("cls");
    puts("========================");
    puts("  Data Mahasiswa Baru  ");
    puts("========================");
    printf("\n\n");
    for(int i=0;i<length;i++){
        printf("Nama Mahasiswa ke %i\n",i+1);
        printf("Nama Mahasiswa : %s\n",maha[i].nama);
        printf("Nilai Matematika : %i\n",maha[i].mate);
        printf("Nilai Bahasa Indonesia : %i\n",maha[i].indo);
        printf("Nilai Bahasa Inggris : %i\n",maha[i].ingg);
        printf("Nilai Kejuruhan : %i \n",maha[i].keju);
        printf("Nilai rata-rata : %.2f\n\n",maha[i].rata);
    }
    system("pause");
}


int main()
{
    struct mahasiswa maha[20];
    int x=99,pilihan,banyak=0;
    do{
    system("cls");
    printf("==================================\n");
    printf(" Program Mahasiswa Baru IT Telkom\n");
    printf("==================================\n");
    puts("1. Input Mahasiswa");
    puts("2. Data Mahasiswa");
    puts("3. Cari Mahasiswa");
    puts("4. Keluar");
    printf("masukkan pilihan : ");
    scanf("%i",&pilihan);

    if(pilihan==1){
        system("cls");
        printf("masukkan banyak mahasisa baru :");
        scanf("%i",&banyak);
        masukan(banyak,&maha[20]);
    }

    else if(pilihan==2){
        if (banyak==0){
            system("cls");
            printf("masukkan data terlebih dahulu!!!\n");
            system("pause");
        }else
        rekap(banyak,&maha[20]);

    }
    // else if(pilihan==3){
    //     system("cls");
    //     int pilihanCari;
    //     printf("==================================\n");
    //     printf(" Jenis Cari Data Mahasiswa \n");
    //     printf("==================================\n");
    //     printf("1. Berdasarkan Nama \n");
    //     printf("2. Berdasarkan Nilai Rata-rata\n");
    //     printf("Masukkan Pilihan : ")
    //     scanf("%d", &pilihanCari);

    //     if (pilihanCari == 1)
    //     {
            
    //         printf("==================================\n");
    //         printf(" Cari Nama Mahasiswa Baru \n");
    //         printf("==================================\n");
    //     }
        

    // }
    else{
    system("cls");
    printf("Harap Masukkan Sesuai Pilihan!!!\n");
    system("pause");
    //system("cls");

    }
    }while(x==99);
    return 0;
}
