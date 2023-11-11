#include <stdio.h>

void main() {

  for (int a = 0; a < 100; a++) {

    if (a == 50)
    {
      break;
    }
    if (a == 10)
    {
      continue;
    }
    printf ("%d\n", a);
    
  }

}
