#include <stdio.h>

int pangkat(int x, int y) {
    if(y > 0){
        return x*pangkat(x,y-1);
    }
    else {
        return 1;
    }
}

int main(){
    printf("%d", pangkat(3,2));
}
