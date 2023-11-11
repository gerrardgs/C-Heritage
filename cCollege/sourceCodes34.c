#include <stdio.h>

int ascending(int n) {
      if (n == 0) {
        return 0;
      }
      else {
        ascending(n-1);
        printf("%d", n);
      }
}

int main() {
  int n;
  printf("");
  scanf("%d", &n);
  ascending(n);
}
