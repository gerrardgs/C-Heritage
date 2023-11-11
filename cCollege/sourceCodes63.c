#include <stdio.h>

int faktorial(int a) {
    
    if(a > 0) {
      printf("%d\n", a);
      return a * faktorial (a-1);
    }else {
        return 1;
    }
}

int main() {
    
    int x = faktorial(5);
    printf("%d", x);
}
