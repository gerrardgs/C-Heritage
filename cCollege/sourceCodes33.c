#include <stdio.h>

int faktorial(int a) {
  for (int b = a - 1; b >= 1; b--)
  {
    a = a * b;
  }
  return a;
  
}

int main(){
  int a;
  printf("");
  scanf("%d", &a);
  printf("%d", faktorial(a));
}
