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
  int kuota;
} Asprak;

typedef struct {
    char nama[MAX_NAMA];
    char mata_kuliah_dipilih[MAX_MK];
    char asprak[MAX_NAMA];
    char tanggal[11];
    char jam[6];
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


void init_data_asprak() {
  strcpy(aspraks[0].nama, "Deden");
  strcpy(aspraks[1].nama, "Daffa"); 
  jumlah_asprak = 2;
}

void tampilkan_jadwal_asprak() {
  printf("=================================================================\n");
  printf("                       JADWAL ASPRAK\n");
  printf("=================================================================\n");
  printf("| Nama Asprak | Mata Kuliah | Kuota | Tanggal    | Jam   | Tempat\n");
    for(int i = 0; i < jumlah_asprak; i++) {
        if(strlen(aspraks[i].mata_kuliah) > 0) {
          printf("| %-11s | %-11s | %-5d | %-7s | %-3s | %s",
            aspraks[i].nama, 
            aspraks[i].mata_kuliah,
            aspraks[i].kuota,
            aspraks[i].tanggal, 
            aspraks[i].jam, 
            aspraks[i].tempat); }
    }
  
}

void daftar_responsi() {
    printf("\n=== PENDAFTARAN RESPONSI ===\n");
    
    // Input data mahasiswa
    Mahasiswa mhs_baru;
    
    printf("Masukkan nama mahasiswa: ");
    while (getchar() != '\n' && !feof(stdin)); 
    scanf("%49[^\n]", mhs_baru.nama);

    printf("\nPilih Mata Kuliah:\n");
    for(int i = 0; i < jumlah_mk; i++) {
        printf("%d. %s\n", i+1, mata_kuliah_list[i]);
    }

    int pilihan_mk;
    printf("Pilihan (1-%d): ", jumlah_mk);

    if (scanf("%d", &pilihan_mk) != 1) {
        printf("Pilihan tidak valid! Harap masukkan angka 1-%d.\n", jumlah_mk);
        while (getchar() != '\n' && !feof(stdin));
        return; 
    } else if(pilihan_mk < 1 || pilihan_mk > jumlah_mk) {
        printf("Pilihan tidak valid!\n");
        return;
    }
    
    strcpy(mhs_baru.mata_kuliah_dipilih, mata_kuliah_list[pilihan_mk-1]);

    printf("\nAsprak yang tersedia untuk %s:\n", mhs_baru.mata_kuliah_dipilih);
    
    int asprak_yang_tersedia[MAX_ASPRAK]; 
    int jumlah_tersedia = 0;

    // Cari dan tampilkan semua asprak yang mengajar MK ini
    for(int i = 0; i < jumlah_asprak; i++) {
        if(strcmp(aspraks[i].mata_kuliah, mhs_baru.mata_kuliah_dipilih) == 0 && aspraks[i].kuota > 0) {
            asprak_yang_tersedia[jumlah_tersedia] = i;
            printf("%d. %s - %s - %s - %s\n", 
                     jumlah_tersedia + 1,
                     aspraks[i].nama, 
                     aspraks[i].tanggal, 
                     aspraks[i].jam, 
                     aspraks[i].tempat);
            jumlah_tersedia++;
        }
    }

    if(jumlah_tersedia == 0) {
        printf("Tidak ada asprak yang tersedia untuk mata kuliah ini atau kuota sudah penuh!\n");
        return;
    }

    // --- pemilihan Asprak di sini ---
    int pilihan_asprak;
    printf("Pilih Asprak (1-%d): ", jumlah_tersedia);
    
    if (scanf("%d", &pilihan_asprak) != 1) {
        printf("Pilihan tidak valid! Harap masukkan angka 1-%d.\n", jumlah_tersedia);
        while (getchar() != '\n' && !feof(stdin));
        return; 
    } else if(pilihan_asprak < 1 || pilihan_asprak > jumlah_tersedia) {
        printf("Pilihan tidak valid!\n");
        return;
    }

    // Ambil indeks asprak yang sebenarnya dari array asprak_yang_tersedia
    int index_asprak_terpilih = asprak_yang_tersedia[pilihan_asprak - 1];
    
    // Simpan data Asprak yang dipilih ke struct Mahasiswa
    strcpy(mhs_baru.asprak, aspraks[index_asprak_terpilih].nama);
    strcpy(mhs_baru.tanggal, aspraks[index_asprak_terpilih].tanggal);
    strcpy(mhs_baru.jam, aspraks[index_asprak_terpilih].jam);

    //  Kurangi kuota asprak
    aspraks[index_asprak_terpilih].kuota--;


    printf("\n=== PENDAFTARAN BERHASIL ===\n");
    printf("Nama Mahasiswa   : %s\n", mhs_baru.nama);
    printf("Mata Kuliah      : %s\n", mhs_baru.mata_kuliah_dipilih);
    printf("Asprak Terpilih  : %s\n", mhs_baru.asprak);
    printf("Tanggal Responsi : %s\n", mhs_baru.tanggal);
    printf("Jam Responsi     : %s\n", mhs_baru.jam);
    printf("Tempat Responsi  : %s\n", aspraks[index_asprak_terpilih].tempat);
    printf("Sisa Kuota Asprak: %d\n", aspraks[index_asprak_terpilih].kuota);
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

    if (scanf("%d", &pilihan_asprak) != 1) {
        printf("Pilihan tidak valid! Harap masukkan angka 1-%d.\n", jumlah_asprak);
        while (getchar() != '\n' && !feof(stdin));
        return; 
    } else if(pilihan_asprak < 1 || pilihan_asprak > jumlah_asprak) {
        printf("Pilihan tidak valid!\n");
        return;
    }

  int index_asprak = pilihan_asprak - 1;
  printf("asprak terpilih: %s\n", aspraks[index_asprak].nama);

   // perbaikan(dari teh belva) tidak boleh menginputkan lagi jadwal setelah sudah ada datanya
  if (strlen(aspraks[index_asprak].mata_kuliah) > 0) {
      printf("\n--- PERINGATAN ---\n");
      printf("Data jadwal responsi sudah ada untuk Asprak %s!\n", 
             aspraks[index_asprak].nama);
      printf("Tidak boleh menginputkan lagi!!\n");
      return;
  }

  printf("\nPilih Mata Kuliah yang diajar:\n");
    for(int i = 0; i < jumlah_mk; i++) {
        printf("%d. %s\n", i+1, mata_kuliah_list[i]);
    }

  int pilihan_mk;
    printf("Pilihan (1-%d): ", jumlah_mk);

    if (scanf("%d", &pilihan_mk) != 1) {
        printf("Pilihan tidak valid! Harap masukkan angka 1-%d.\n", jumlah_mk);
        while (getchar() != '\n' && !feof(stdin));
        return; 
    } else if(pilihan_mk < 1 || pilihan_mk > jumlah_mk) {
        printf("Pilihan tidak valid!\n");
        return;
    }

    // menyalin nama MK yang di pilih oleh asprak
    strcpy(aspraks[index_asprak].mata_kuliah, mata_kuliah_list[pilihan_mk - 1]);

    printf("\nBatas Kuota Mahasiswa (Angka)\t: ");

    scanf("%d", &aspraks[index_asprak].kuota);

    printf("Tanggal (DD-MM-YYYY)   \t\t: ");
    scanf("%s", aspraks[index_asprak].tanggal);

    printf("Jam (HH:MM)   \t\t\t: ");
    scanf("%s", aspraks[index_asprak].jam);

    printf("Tempat   \t\t\t: ");
    getchar();
    fgets(aspraks[index_asprak].tempat, 20, stdin);

    printf("\n--- Jadwal berhasil diinput! ---\n");
    printf("Asprak       : %s\n", aspraks[index_asprak].nama);
    printf("Mata Kuliah  : %s\n", aspraks[index_asprak].mata_kuliah);
    printf("Kuota        : %d\n", aspraks[index_asprak].kuota);
    printf("Tanggal      : %s\n", aspraks[index_asprak].tanggal);
    printf("Jam          : %s\n", aspraks[index_asprak].jam);
    printf("Tempat       : %s\n", aspraks[index_asprak].tempat);
}

void hapus_data_mahasiswa() {

}

void tampilkan_menu () {
  printf("\n=== SISTEM PENDAFTARAN RESPONSI ===\n");
  printf("1. Input Jadwal Responsi (Asprak)\n");
  printf("2. Daftar Responsi (Mahasiswa)\n");
  printf("3. Cari Mahasiswa\n");
  printf("4. Lihat Jadwal Asprak\n");
  printf("5. Hapus data Mahasiswa\n");
  printf("6. Keluar\n");
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
            input_jadwal_asprak();
            break;
          case 2:
            daftar_responsi();
            break;
          case 3:
            tampilkan_cari_mahasiswa();
            break;
          case 4:
            tampilkan_jadwal_asprak();
            break;
          case 5:
            hapus_data_mahasiswa();
            break;
          case 6:
            printf("\nTerima kasih! Program selesai.\n");
            break;
          default:
          printf("Pilihan tidak valid! Silakan pilih 1-5.\n");
    }
  } while (pilihan != 6);
  
  return 0;
}