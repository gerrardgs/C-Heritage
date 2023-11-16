#include <stdio.h>

int main() {
    int arr[3][2] = {{3,6},{9,8},{15,10}};
    int target = 15;
    int i, j;
    int found = 0;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if (arr[i][j] == target) {
                printf("%d berada di index [%d][%d]\n", target, i, j);
                found = 1;
                break;
            }
        }
        if (found == 1) {
            break;
        }
    }
    
    if (found == 0) {
        printf("%d tidak ditemukan dalam array\n", target);
    }
    
    return 0;
}
