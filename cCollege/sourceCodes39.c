#include <stdio.h>

int main () {
    char name[20], web[30];
    printf("Nama: ");
    scanf("%s", &name);
    fflush(stdin);
    printf("web: ");
    scanf("%s", &web);

    printf("Nama yang diinputkan: %s\n", name);
    printf("Web yang diinputkan: %s\n", web);
    
    return 0;
}
