#include <stdio.h>

int main(){
    char str[50];
    FILE *fptr = NULL;

    fptr = fopen("file.txt", "w");

    if(fptr == NULL){
        printf("Error");
        exit(1);
    }
}
