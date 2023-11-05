#include<stdio.h>

int main()
{
    char kata[100];
    int a;

    printf("Masukkan kata : ");
    fgets(kata, sizeof(kata), stdin);
    int freq[26] = {0};

    for (a = 0; kata[a]; a++)
    {
        freq[kata[a]-'a'] += 1;
    }

    for (a = 0; a < 26; a++)
    {
        if (freq[a] != 0)
        {
            char kalimat = 'a' + a;
            printf("\tHuruf %c ada %d\n", kalimat, freq[a]);
        }
    }
    return 0;
}
