/* JAWABAN Latihan Single Linked List */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact{
    char name[50];
    char phone[15];
    struct Contact* next;
} Contact;

void addContact(Contact** head, char* name, char* phone){
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;

    if(*head == NULL){
        *head = newContact;
    } else{
        Contact* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newContact;
    }
    printf("Kontak berhasil ditambahkan.\n");
}

void findContact(Contact* head, char* name){
    Contact* temp = head;
    int found = 0;
    while(temp != NULL){
        if(strcmp(temp->name, name) == 0){
            printf("Nama: %s\n", temp->name);
            printf("Nomor telepon: %s\n", temp->phone);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if(!found){
        printf("Kontak tidak ditemukan.\n");
    }
}

void printContacts(Contact* head){
    Contact* temp = head;
    if(temp == NULL){
        printf("Daftar kontak kosong.\n");
    } else{
        printf("Daftar Kontak:\n");
        while(temp != NULL){
            printf("Nama: %s\n", temp->name);
            printf("Nomor telepon: %s\n", temp->phone);
            printf("-------------------\n");
            temp = temp->next;
        }
    }
}

int main(){
    Contact* contacts = NULL;
    int choice;
    char name[50], phone[15];
    do{
        printf("Menu:\n");
        printf("1. Tambah Kontak\n");
        printf("2. Cari Kontak\n");
        printf("3. Cetak Daftar Kontak\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Masukkan Nama: ");
                scanf("%s", name);
                printf("Masukkan Nomor Telepon: ");
                scanf("%s", phone);
                addContact(&contacts, name, phone);
                break;
            case 2:
                printf("Masukkan Nama yang Dicari: ");
                scanf("%s", name);
                findContact(contacts, name);
                break;
            case 3:
                printContacts(contacts);
                break;
            case 4:
                printf("Terima kasih. Sampai jumpa!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
        printf("\n");
    } while(choice != 4);
    return 0;
}
