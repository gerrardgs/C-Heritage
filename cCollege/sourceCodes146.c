#include <stdio.h>

int search(int x, int y){
    if(y == 0){
        return 1;
    }
    else{
        return x * search(x, y - 1);
    }
}

int main(){
    int x, y;
    printf("Masukkan Nilai x: ");
    scanf("%d", &x);
    printf("Masukkan Nilai y (Nilai Pangkat): ");
    scanf("%d", &y);
    int result = search(x, y);
    printf("%d ^ %d = %d\n", x, y, result);
    return 0;
}
