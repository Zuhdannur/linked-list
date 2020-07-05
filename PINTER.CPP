#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <alloc.h>
#include <string.h>
#include <ctype.h>


#define PANJANG_NOMOR 5
#define PANJANG_NAMA 20


struct simpul_siswa {
    char nomor[PANJANG_NOMOR + 1];
    char nama[PANJANG_NAMA + 1];
    struct simpul_siswa *lanjutan;
};

struct simpul_siswa *ptr_kepala=NULL;

void tampilkan_data(void);
void pemasukan_data(void);
void masukan_string(char *keterangan,char *masukan,int panjang_maks);


main() {
    clrscr();

    //Contoh Pembuktian Sampul LinkedList Pointer

    struct simpul_siswa *ptr_baru;
    ptr_baru = (struct simpul_siswa *)malloc(sizeof(struct simpul_siswa));
//    ptr_baru->nomor="11511";
    strcpy(ptr_baru->nomor,"11511");
    strcpy(ptr_baru->nama,"RUDI");
//    ptr_baru->nama="RUDI";
    ptr_baru->lanjutan = ptr_kepala;
    ptr_kepala = ptr_baru;

    ptr_baru = (struct simpul_siswa *)malloc(sizeof(struct simpul_siswa));
    strcpy(ptr_baru->nomor,"11512");
    strcpy(ptr_baru->nama,"SITI");
//    ptr_baru->nomor="11512";
//    ptr_baru->nama="SITI";
    ptr_baru->lanjutan = ptr_kepala;
    ptr_kepala = ptr_baru;
//    pemasukan_data();
    tampilkan_data();

    getch();

}

void tampilkan_data(void) {
    struct simpul_siswa *ptr_sementara;
    puts("\n Isi daftar berantai : \n");
    ptr_sementara = ptr_kepala;
    while(ptr_sementara){
        printf("%s %s\n",ptr_sementara->nomor,ptr_sementara->nama);
        ptr_sementara = ptr_sementara->lanjutan;
    }
}

void pemasukan_data(void) {
    char jawaban;
    struct simpul_siswa *ptr_baru;

    do {
        ptr_baru=(struct simpul_siswa *)malloc(sizeof(struct simpul_siswa));
        if(ptr_baru){
            masukan_string("Nomor Siswa :",ptr_baru->nomor,PANJANG_NOMOR);
            masukan_string("Nama Siswa :",ptr_baru->nama,PANJANG_NAMA);

            ptr_baru->lanjutan = ptr_kepala;
            ptr_kepala=ptr_baru;

            printf("Memasukan data lagi ?");
            do {
                jawaban = toupper(getch());
            }while(!(jawaban == 'Y' || jawaban== 'T'));

        } else {
            puts("Memori Tidak Cukup");
            break;
        }
    }while(jawaban == 'Y');
}

void masukan_string(char *keterangan,char *masukan,int panjang_maks) {
    char st[256];
    do {
        printf(keterangan);
        gets(st);
        if(strlen(st)>panjang_maks)
            printf("Terlalu panjang . Maks %d karakter \n",panjang_maks);
    }while(strlen(st) > panjang_maks);
    strcpy(masukan,st);
}