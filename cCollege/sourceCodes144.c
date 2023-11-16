#include <stdio.h>

// rekursif faktorial
// Fungsi untuk menghitung faktorial dari n secara rekursif
int faktorial(int n){
    // Basis: jika n = 0 atau n = 1, maka faktorial(n) = 1
    if(n == 0 || n == 1){
    return 1;
    }
    // Rekurens: jika n > 1, maka faktorial(n) = n * faktorial(n-1)
    else{
    return n * faktorial(n-1);
    }
}

// rekursif fibonacci
// Fungsi untuk menghitung bilangan Fibonacci ke-n secara rekursif
int fibonacci(int n){
    // Basis: jika n = 0, maka fibonacci(n) = 0; jika n = 1, maka fibonacci(n) = 1
    if(n == 0){
    return 0;
    }
    else if(n == 1){
    return 1;
    }
    // Rekurens: jika n > 1, maka fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)
    else{
    return fibonacci(n-1) + fibonacci(n-2);
    }
}

