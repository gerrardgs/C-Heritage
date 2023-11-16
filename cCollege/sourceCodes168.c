#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Fungsi untuk mengecek apakah suatu angka merupakan bilangan prima atau bukan
int is_prime(int num) {
    if (num <= 1)
        return 0;

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

// Fungsi untuk mengecek bilangan prima dengan menggunakan multithreading
void *check_prime(void *arg) {
    int num = *(int*)arg;
    if (is_prime(num))
        printf("%d prima\n", num);
    else
        printf("%d bukan prima\n", num);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <angka1> <angka2> ... <angkaN>\n", argv[0]);
        return 1;
    }

    pthread_t threads[argc - 1];
    int numbers[argc - 1];

    for (int i = 1; i < argc; ++i) {
        numbers[i - 1] = atoi(argv[i]);
        pthread_create(&threads[i - 1], NULL, check_prime, &numbers[i - 1]);
    }

    for (int i = 0; i < argc - 1; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
