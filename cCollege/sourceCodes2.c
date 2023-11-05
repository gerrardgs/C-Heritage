#include <stdio.h>
#include <string.h>

int char_count[26];
char caracter[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char capital_caracter[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main() {
    char str[100];
    scanf("%[^\n]%*c", str); // Read the input string
    int len = strlen(str); // Calculate the length of the input string

    for (int i = 0; i < len; i++) { // Loop through each character of the input string
        for (int j = 0; j < 26; j++) { // Check if the current character matches any alphabet
            if (str[i] == caracter[j] || str[i] == capital_caracter[j]) { // If it matches, increment the corresponding count
                char_count[j]++;
            }
        }
    }

    for (int i = 0; i < 26; i++) { // Loop through the character counts
        if (char_count[i] != 0) { // Print the count for each alphabet that appeared
            printf("huruf %c ada %d\n", caracter[i], char_count[i]);
        }
    }

    return 0;
}
