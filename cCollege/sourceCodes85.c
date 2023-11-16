#include <stdio.h>
#define maxfloors 10

int main(){
    int floors[maxfloors] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int currentfloor;
    int y, z;

    printf("Masukkan nomor lantai: ");
    scanf("%d", &currentfloor);

    int currentfloorx = -1;
    for(y = 0; y < maxfloors; y++){
        if(floors[y] == currentfloor){
            currentfloorx = y;
            break;
        }
    }
    if(currentfloorx == -1){
        printf("Lantai yang dipilih tidak valid.\n");
    } else{
        int firstfloorx = currentfloorx - 2;
        if(firstfloorx < 0){
            firstfloorx = 0;
        }

        int lastfloorx = firstfloorx + 4;
        if(lastfloorx >= maxfloors){
            lastfloorx = maxfloors - 1;
            firstfloorx = lastfloorx - 4;
        }

        for(z = firstfloorx; z <= lastfloorx; z++){
            printf("%d ", floors[z]);
        }
        printf("\n");
    }
}
