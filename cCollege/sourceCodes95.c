#include <stdio.h>

typedef struct Manager
{
    char age;
    int unit;
} Manager;

struct Nama
{
    int *firstname;
    int *lastname;

    struct Manager data_Manager; // Perbaikan: Menggunakan nama struct yang benar
};

int main()
{
    struct Nama nama;

    // Mengisi data Manager
    nama.data_Manager.age = 'A';
    nama.data_Manager.unit = 10;

    // Mengisi data Nama
    int firstName = 123;
    int lastName = 456;

    nama.firstname = &firstName;
    nama.lastname = &lastName;

    // Menampilkan output
    printf("Age: %c\n", nama.data_Manager.age);
    printf("Unit: %d\n", nama.data_Manager.unit);
    printf("First Name: %d\n", *nama.firstname);
    printf("Last Name: %d\n", *nama.lastname);

    return 0;
}
