#ifndef TAMBAH_H
#define TAMBAH_H

#include<string>
using namespace std;

struct reservasi
{
    int no_reservasi;
    string nama;
    int jumlah_orang;
    string tanggal;
    string jam;
    reservasi *next;
    reservasi *prev;
};

void tambah_reservasi(int no_reservasi, string nama, int jumlah_orang, string tanggal, string jam);
void lihat_reservasi();
void daftar_pilihan();

#endif