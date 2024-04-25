#ifndef TAMBAH_H
#define TAMBAH_H

#include<string>


struct reservasi
{
    int no_reservasi;
    std::string nama;
    int jumlah_orang;
    std::string tanggal;
    std::string jam;
    reservasi *next;
    reservasi *prev;
};

void tambah_reservasi(int no_reservasi, std::string nama, int jumlah_orang, std::string tanggal, std::string jam);
void lihat_reservasi();
void daftar_pilihan();

extern reservasi* head;
extern reservasi* tail;

extern int no_reservasi;
extern std::string nama;
extern int jumlah_orang;
extern std::string tanggal;
extern std::string jam;
extern reservasi *next;
extern reservasi *prev;

#endif