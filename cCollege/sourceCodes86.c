#include <stdio.h>

int main()
{
    char arr[] = {"nama saya jokowi dodo, presiden indonesia ke6 menang dua periode dari partai PDIP"};
    int size = sizeof(arr);
    int count = 0;
    
    for(int i = 0; i < size; i++)
    {
        if (arr[i] != ' ')
        {
            printf("%c", arr[i]);
            count++;
        }
        printf("%d\n", count-1);
    }
}
