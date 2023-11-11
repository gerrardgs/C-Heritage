#include <stdio.h>

int power(int a, int n){
    if(n > 0)       // recursive case
        return a*power(a, n - 1);
    else            // base case
        return 1;
}

int main(){
    int basis, pangkat;
    printf("Masukkan bilangan basis: ");
    scanf("%d", &basis);

    printf("Masukkan bilangan pangkat: ");
    scanf("%d", &pangkat);

    int result = power(basis, pangkat);
    
    printf("Hasil dari %d^%d adalah %d", basis, pangkat, result);
    return 0;
}
