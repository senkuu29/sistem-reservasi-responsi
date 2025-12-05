#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ASPRAK 10
#define MAX_MAHASISWA 50
#define MAX_NAMA 50
#define MAX_MK 30

typedef struct {
  char nama[MAX_ASPRAK];
  char mata_kuliah[MAX_MK];
  char tanggal[11];
  char jam[6];
  char tempat[20];
} Asprak;

typedef struct {
  char nama[MAX_ASPRAK];
  char mata_kuliah[MAX_MK];
  char tanggal[11];
  char jam[6];
  char tempat[20];
} Mahasiswa;

Asprak aspraks[MAX_ASPRAK];
int jumlah_asprak = 0;

char mata_kuliah_list[][MAX_MK] = {
    "Alpro",
    "Kalkulus", 
    "Basdat",
    "Peweb",
    "pbo"
};
int jumlah_mk = 5;


void init_data_asprak();
void input_jadwal_asprak();

void init_data_asprak() {
  strcpy(aspraks[0].nama, "Deden ahmad");
  strcpy(aspraks[1].nama, "Daffa"); 
  jumlah_asprak = 2;
}

void tampilkan_jadwal_asprak() {

}

void daftar_responsi() {

}

void tampilkan_cari_mahasiswa() {

}

void input_jadwal_asprak() {
  printf("\n=== INPUT JADWAL RESPONSI===\n");

  printf("Pilih Asprak:\n");
  for (int i = 0; i < jumlah_asprak; i++) {
    printf("%d. %s\n",i+1, aspraks[i].nama);
  }

  int pilihan_asprak;
  printf("Pilihan (1-%d): ", jumlah_asprak);
  scanf("%d", &pilihan_asprak);

  if(pilihan_asprak < 1 || pilihan_asprak > jumlah_asprak) {
      printf("Pilihan tidak valid!\n");
      return;
  }

  int index_asprak = pilihan_asprak - 1;
  printf("Asprak terpilih: %s\n", aspraks[index_asprak].nama);
}


void tampilkan_menu () {
  printf("\n=== SISTEM PENDAFTARAN RESPONSI ===\n");
  printf("1. Lihat Jadwal Asprak\n");
  printf("2. Daftar Responsi (Mahasiswa)\n");
  printf("3. Cari Mahasiswa\n");
  printf("4. Input Jadwal Responsi (Asprak)\n");
  printf("5. Keluar\n");
  printf("Pilihan Anda: ");
}

int main() {
    //pemanggilan fungsi nama" data asprak
    init_data_asprak();

    int pilihan;

    printf("=========================================\n");
    printf("\tSISTEM RESERVASI RESPONSI\n");
    printf("=========================================\n");
  
  do {
      tampilkan_menu();
      scanf("%d", &pilihan);

      switch (pilihan) {
          case 1:
            tampilkan_jadwal_asprak();
            break;
          case 2:
            daftar_responsi();
            break;
          case 3:
            tampilkan_cari_mahasiswa();
            break;
          case 4:
            input_jadwal_asprak();
            break;
          case 5:
            printf("\nTerima kasih! Program selesai.\n");
            break;
          default:
          printf("Pilihan tidak valid! Silakan pilih 1-5.\n");
    }
  } while (pilihan != 5);
  
  return 0;
}