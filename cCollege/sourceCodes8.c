#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    printf(""); scanf("%d", &a);
    printf("");

    for(b=a; b>=1; b--)
    {
        for(c=1; c<=b; c++)
        {
            printf("*");
        }
    printf("\n");
    }
return 0;

}
