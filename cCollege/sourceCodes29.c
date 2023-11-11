#include <stdio.h>

void arithmetic(int a, int b){
    printf("\n%d + %d = %d",a,b,a+b);  //dengan prosedur kode 3 kali lebih singkat
    printf("\n%d - %d = %d",a,b,a-b);
    printf("\n%d / %d = %d",a,b,a/b);
    printf("\n%d * %d = %d",a,b,a*b);
    printf("\n");
}

int main (void){
    arithmetic(9,10);
    arithmetic(8,4);
    arithmetic(7,4);
return 0;
}
