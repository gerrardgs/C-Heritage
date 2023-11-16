#include <stdio.h>

int main()
{
    char arr[3][10] = {"Hallo", "Gojo", "Satoru"};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(arr[i][j] != 'o')
            printf("%c", arr[i][j]);
        }
    }
}
