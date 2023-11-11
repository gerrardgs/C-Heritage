#include <stdio.h>

int main(){
    int angka[10]={8,5,2,6,9,3,1,4,0,7};
	//Melakukan looping sebanyak jumlah data
	for(int i=0; i<10; i++){
		//Anggap index ke i adalah angka terkecil
		int indexNilaiMinimal=i;
		//Looping untuk mencari angka yang terkecil dengan membandingkan setiap angka
		for(int j=i; j<10; j++){
			//Jika ada yang lebih kecil dari angka index ke indexNilaiMinimal
			if(angka[j]<angka[indexNilaiMinimal]){
				//maka, ganti indexNilaiMinimal menjadi index angka tersebut
				indexNilaiMinimal=j;
			}
		}
		//Swap value
		int temp=angka[i];
		angka[i]=angka[indexNilaiMinimal];
		angka[indexNilaiMinimal]=temp;
	}
	//Cetak data
	for(int i=0; i<10; i++){
		printf("%d ", angka[i]);
	}
}
