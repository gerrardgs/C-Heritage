#include <stdio.h>

int main ()
{
    char arr[] = "nama saya jokowi dodo, presiden indonesia ke6 menang dua periode dari partai PDIP";
    int arrSir = sizeof(arr), spasi = 0;

    for(int a = 0; a < arrSir; a++){
        if(arr[a] == ' '){
            spasi++;
        }
    }
    printf("%d", spasi+1);
}
