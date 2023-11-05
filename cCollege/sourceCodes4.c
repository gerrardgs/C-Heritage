#include <stdio.h>
#include <string.h>
#include <time.h>

// Definisikan struct untuk data peminjam
struct Peminjam {
    char nama[100];
    char keterangan[100];
    struct tm jangkaWaktu;
};

struct Mahasiswa {
    struct Peminjam peminjam;
    char nim[20];
    char prodi[50];
};

// Definisikan array untuk menyimpan data peminjaman
struct Mahasiswa daftarMahasiswa[100];
int jumlahMahasiswa = 0;

// Prosedur untuk menambahkan data peminjaman aula
void tambahPeminjaman() {
    struct Mahasiswa peminjamBaru;
    printf("Masukkan nama: ");
    scanf("%s", peminjamBaru.peminjam.nama);
    printf("Masukkan NIM: ");
    scanf("%s", peminjamBaru.nim);
    printf("Masukkan prodi: ");
    scanf("%s", peminjamBaru.prodi);
    printf("Masukkan keterangan: ");
    scanf("%s", peminjamBaru.peminjam.keterangan);

    // Masukkan tanggal dan waktu mulai peminjaman
    printf("Masukkan tanggal mulai peminjaman (dd mm yyyy): ");
    scanf("%d %d %d", &peminjamBaru.peminjam.jangkaWaktu.tm_mday, &peminjamBaru.peminjam.jangkaWaktu.tm_mon, &peminjamBaru.peminjam.jangkaWaktu.tm_year);
    peminjamBaru.peminjam.jangkaWaktu.tm_mon -= 1; // Bulan dimulai dari 0 sampai 11
    peminjamBaru.peminjam.jangkaWaktu.tm_year -= 1900; // Tahun dimulai dari 1900
    printf("Masukkan waktu mulai peminjaman (hh mm): ");
    scanf("%d %d", &peminjamBaru.peminjam.jangkaWaktu.tm_hour, &peminjamBaru.peminjam.jangkaWaktu.tm_min);

    // Masukkan jangka waktu peminjaman (dalam menit)
    int jangkaWaktu;
    printf("Masukkan jangka waktu peminjaman (dalam menit): ");
    scanf("%d", &jangkaWaktu);
    peminjamBaru.peminjam.jangkaWaktu.tm_sec = 0; // set detik menjadi 0
    peminjamBaru.peminjam.jangkaWaktu.tm_isdst = -1; // jangan khawatir tentang daylight saving time
    // jangka waktu peminjaman ditambahkan ke waktu mulai
    peminjamBaru.peminjam.jangkaWaktu.tm_min += jangkaWaktu;
    mktime(&peminjamBaru.peminjam.jangkaWaktu);

    daftarMahasiswa[jumlahMahasiswa] = peminjamBaru;
    jumlahMahasiswa++;
}
