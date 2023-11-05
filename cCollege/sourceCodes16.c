#include <stdio.h>
#include <string.h>

// Fungsi rekursif untuk mencetak semua subsekuen dari string
void printSubsequences(char* str, int index, char* current)
{
    // Base case: mencetak subsekuen yang terbentuk saat ini
    if (index == strlen(str)) {
        printf("%s ", current);
        return;
    }

    // Panggil fungsi dengan mengabaikan karakter saat ini
    printSubsequences(str, index + 1, current);

    // Panggil fungsi dengan menyertakan karakter saat ini
    current[strlen(current)] = str[index];
    current[strlen(current) + 1] = '\0'; // Menambahkan null terminator
    printSubsequences(str, index + 1, current);
}

int main()
{
    char str[100];

    printf("Masukkan string: ");
    scanf("%99s", str); // Mengubah format specifier menjadi %99s

    printf("Subsekuen yang mungkin adalah: \n");
    char current[100] = "";
    printSubsequences(str, 0, current);

    return 0;
}
