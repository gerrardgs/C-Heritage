nt jumlah = 13;

// membuat pointer untuk variabel jumlah
int *ptr_1;
// menyimpan alamat memori dari variabel jumlah
ptr_1 = &jumlah;

// membuat pointer untuk pointer ptr_1
int **ptr_2;
// menyimpan alamat memori dari pointer ptr_1
ptr_2 = &ptr_1;

// Menampilkan value dari variabel jumlah
printf("Value jumlah = %d\n", jumlah);
printf("Value jumlah menggunakan single pointer = %d\n", *ptr_1);
printf("Value jumlah menggunakan double pointer = %d\n", **ptr_2);
