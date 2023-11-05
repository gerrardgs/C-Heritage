#include <stdio.h>

int main() {
    char arr[] = "Nama Saya Joko Widodo";
    int count = 0;

    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] != ' ') {
            printf("%c", arr[i]);
            count++;
        }
    }

    printf("\n%d", count);
    return 0;
}
