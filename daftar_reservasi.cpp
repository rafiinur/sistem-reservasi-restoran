#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Reservasi
{
    string Nama_pelanggan;
    string tanggal_dan_waktu;
    int jumlah_orang;
    int nomor_meja;
};

bool perbandingan_reservasi(const Reservasi &a, const Reservasi &b)
{
    return a.tanggal_dan_waktu < b.tanggal_dan_waktu;
}

void Menampilkan_detail_reservasi(const Reservasi &res)
{
    cout << "Nama Pelanggan: " << res.Nama_pelanggan << endl;
    cout << "Tanggal dan Waktu Reservasi: " << res.tanggal_dan_waktu << endl;
    cout << "Jumlah Orang: " << res.jumlah_orang << endl;
    cout << "Nomor Meja: " << res.nomor_meja << endl;
    cout << endl;
}

int main()
{
    vector<Reservasi> Reservasi = {
        {"Trias", "11-03-2024 09:00 WIB", 3, 1},
        {"Ahmad", "13-04-2024 10:00 WIB ", 2, 1},
        {"Dadung", "14-04-2024 12:00 WIB", 5, 4},
    };

    sort(Reservasi.begin(), Reservasi.end(), perbandingan_reservasi);

    cout << "Daftar Reservasi:" << endl;
    cout << "-----------------" << endl;

    for (const auto &res : Reservasi)
    {
        Menampilkan_detail_reservasi(res);
    }

    return 0;
}
