#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int a,b;    
    scanf("%d",&a);  
    b=a;  
   for(int i=1;i<=a;i++)  
   {  
       for(int j=1;j<=b-1;j++)  
       {  
           printf(" ");  
       }  
       for(int k=1;k<=2*i-1;k++)  
       {  
          if(k==1 || k==2*i-1 || i==a)  
         printf("*");  
         else  
         printf(" ");  
       }  
       b--;  
     
      printf("\n");  
    }  
    return 0;
}
