#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#define CHUNK 1024

typedef struct student{
    char name[20];
    char school[20];
    char gender[10];
    char place_of_birth[10];
    int date_of_birth[20];

}student;

void input_data(){

    struct student s;

    FILE *file;
    file = fopen("DataSiswa.txt","a");

    if(file == NULL)
    {
        printf("Error Membuka File!");                
    }

    printf("Masukan Nama : ");
    scanf(" %[^\n]s",s.name);
    fflush(stdin);

    printf("Asal Sekolah : ");
    scanf("%[^\n]s",s.school);
    fflush(stdin);

    printf("Jenis Kelamin (Laki/Perempuan) : ");
    scanf("%[^\n]s",s.gender);
    fflush(stdin);

    printf("Kota Asal : ");
    scanf("%s",s.place_of_birth);
    fflush(stdin);

    printf("Tanggal Lahir (dd/mm/yy) : ");
    scanf("%s",s.date_of_birth);
    printf("\n");

    fprintf(file,"%s",s.name);
    fprintf(file," %s ",s.gender);
    fprintf(file,"(%s),",s.school);
    fprintf(file," %s",s.place_of_birth);
    fprintf(file," (%s)\n",s.date_of_birth);

    fclose(file);
}

void show_data(){

    char buf[CHUNK];
    
    int compare_strings(const void *a, const void *b){
        const char *ia = *(const char **)a;
        const char *ib = *(const char **)b;
        return tolower(ia[0]) - tolower(ib[0]);
    }

    FILE *file;
    size_t nread;
    char **lines = NULL;
    int num_lines = 0;

    file = fopen("DataSiswa.txt", "r");
    if (file) {
        while ((nread = fread(buf, 1, sizeof buf, file)) > 0){
            buf[nread] = '\0';
            char *p = strtok(buf, "\n");
            while (p) {
                lines = realloc(lines, sizeof(char*) * (num_lines + 1));
                lines[num_lines++] = strdup(p);
                p = strtok(NULL, "\n");
            }
        }
        if (ferror(file)) {}
        fclose(file);
        qsort(lines, num_lines, sizeof(char*), compare_strings);

        file = fopen("DataSiswa.txt", "w");
        if (file) {
            for (int i = 0; i < num_lines; i++) {
                fprintf(file, "%s\n", lines[i]);
                printf("%s\n", lines[i]);
                free(lines[i]);
            }
            free(lines);
            fclose(file);
        }
    }
}

void edit_data(){

    char buf[CHUNK];
    char search[20];
    char replace[20];
    int line_number;

    printf("Masukan Angka Baris : ");
    scanf("%d", &line_number);
    fflush(stdin);

    printf("Masukan Data Yang Ingin di Ganti : ");
    scanf(" %[^\n]s", search);
    fflush(stdin);

    printf("Masukan Data Baru : ");
    scanf(" %[^\n]s", replace);
    fflush(stdin);

    FILE *file;
    file = fopen("DataSiswa.txt", "r+");
    if (file == NULL) {
        printf("Error Membuka File!\n");
        return;
    }

    int current_line = 1;
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        printf("Error!\n");
    }

    while (fgets(buf, CHUNK, file) != NULL) {
        if (current_line == line_number) {
            
            char *pos = strstr(buf, search);
            if (pos != NULL) {
                
                int offset = pos - buf;
                int searchLen = strlen(search);
                int replaceLen = strlen(replace);
                int bufferLen = strlen(buf);

                memmove(buf + offset + replaceLen, buf + offset + searchLen, bufferLen - offset - searchLen + 1);
                
                memcpy(buf + offset, replace, replaceLen);
            }
        }
        fputs(buf, temp_file);
        current_line++;
    }

    fclose(file);
    fclose(temp_file);

    remove("DataSiswa.txt");
    rename("temp.txt", "DataSiswa.txt");
}

void delete_data(){

    char buf[CHUNK];
    int line_number;
    int total_lines = 0;

    printf("Masukan Baris Data Yang Ingin di Hapus : ");
    scanf("%d", &line_number);
    fflush(stdin);

    FILE *file;
    file = fopen("DataSiswa.txt", "r+");
    if (file == NULL) {
        printf("Error!\n");
    }

    while (fgets(buf, CHUNK, file) != NULL) {
        total_lines++;
    }
    rewind(file);

    if (line_number < 1 || line_number > total_lines) {
        printf("Error!\n");
        return;
    }

    FILE *temp_file = fopen("temp.txt", "w");
    int current_line = 1;
    int found = 0;
    while (fgets(buf, CHUNK, file) != NULL) {
        if (current_line == line_number) {
            
            found = 1;
        }
        else if (current_line != line_number || !found) {
            fputs(buf, temp_file);
        }
        current_line++;
    }
    if(found)
        fclose(file);
    fclose(temp_file);

    remove("DataSiswa.txt");
    rename("temp.txt", "DataSiswa.txt");
}

void search_data(){

    char buf[CHUNK];
    char search_word[100];
    int line_number = 0;
    int found = 0;

    fflush(stdin);
    printf("Masukan Nama Yang Imgin di Cari : ");
    scanf("%[^\n]s", search_word);
    fflush(stdin);

    for (int i = 0; i < strlen(search_word); i++) {
        search_word[i] = tolower(search_word[i]);
    }

    FILE *file;
    file = fopen("DataSiswa.txt", "r+");
    if (file == NULL) {
        printf("Error Membuka File!\n");
    }

    while (fgets(buf, CHUNK, file) != NULL) {
        line_number++;

        for (int i = 0; i < strlen(buf); i++) {
            buf[i] = tolower(buf[i]);
        }

        if (strstr(buf, search_word) != NULL) {
            found = 1;
            printf("Data Ditemukan (Line %d) : %s\n", line_number, buf);
        }
    }

    if (!found) {
        printf("Data Tidak Ditemukan\n");
    }
    fclose(file);
}
   
int main(){

    char buf[CHUNK];
    int choice, choice_;

    do{
        printf("\n----------MENU-----------");
        printf("\n|1. Masukan Data\t|");
        printf("\n|2. Lihat Data\t\t|");
        printf("\n|0. Exit        \t|");
        printf("\n-------------------------");
        printf("\nPilihan : ");
        scanf("%d",&choice);
        printf("\n");

        switch(choice){
            case 1:
                system("cls");
                input_data();
            break;
            case 2:
                system("cls");
                do{
                    show_data();

                    printf("\n-----------------");
                    printf("\n|1. Tambah Data\t|");
                    printf("\n|2. Edit Data\t|");
                    printf("\n|3. Hapus Data\t|");
                    printf("\n|4. Search Data\t|");
                    printf("\n|0. Kembali\t|");
                    printf("\n-----------------");
                    printf("\nPilihan : ");
                    scanf("%d",&choice_);
                    printf("\n");

                    switch(choice_){
                    case 1:
                        system("cls");
                        input_data();
                        break;
                    case 2:
                        system("cls");
                        edit_data();
                        break;
                    case 3:
                        system("cls");
                        delete_data();
                        break;
                    case 4:
                        system("cls");
                        search_data();
                        break;
                    case 0:
                        system("cls");
                        break; 
                    }   
                }while(choice_!=0);
                break;                       
        }
    }while(choice!=0);
    system("cls");
    return 0;
}
