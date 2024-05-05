#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <sstream>
#include "header/struct.h"
#include "header/tambah_reservasi.h"

using namespace std;

void time_check(int no_reservasi, string nama, int jumlah_orang, string tanggal, string jam)
{
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    tm *time_info = std::localtime(&now);

    int year = time_info->tm_year + 1900;
    int month = time_info->tm_mon + 1; 
    int day = time_info->tm_mday; 
    int hour = time_info->tm_hour;
    int minute = time_info->tm_min;

    stringstream raw_tanggal (tanggal);
    stringstream raw_jam (jam);

    int tgl, bln, thn, jm, mnt;
    char del_tgl, del_bln, del_jam;

    raw_tanggal >> tgl >> del_tgl >> bln >> del_bln >> thn;
    raw_jam >> jm >> del_jam >> mnt;



    if (thn < year or thn > year) // Cek tahun -> harus tahun ini
    {
        cout << "Silahkan reservasi di tahun ini";
    }
    else
    {
        if (bln == month)
        {
            if (tgl - day < 7 ) // jika h-7 tidak bisa pesan
            {
                cout << "Silahkan pesan di hari lain, tanggal terlalu dekat / terlewat";
            }
            else
            {
                if (jm >= 21 && jm < 5) // reservasi tidak lebih dari jam 21.00 dan kurang dari jam 5
                {
                    cout << "Toko Tutup";
                }
                else
                {
                    if (hour >= 21 && hour < 5) // Toko tutup pada jam 21 dan buka jam 6
                    {
                        cout << "Sistem reservasi sudah tutup";
                    }
                    else
                    {
                        addReservation(reservasi, {no_reservasi, nama, jumlah_orang, tanggal, jam});
                    }
                }
            }

        } 
        else if (bln < month or bln > month + 2) // reservasi tidak bisa dilakukan jika bulan terlewat atau lebih dari 2 bulan
        {
            cout << "Pesanan tidak bisa dilakukan, silahkan pilih hari lain";
        }    
    }

} 


void addReservation(Node *&head, const Reservasi &reservasi) {
    Node *newNode = new Node;
    newNode->data = new Reservasi;
    *(newNode->data) = reservasi;
    newNode->next = head;
    head = newNode;
}

void createReservation()
{
    int no_reservasi = 1;
    string nama;
    int jumlah_orang;
    string tanggal;
    string jam;

    cout << endl;
    cout << "========Buat Reservasi========" << endl;
    cout << "Masukkan Nama: "; 
    cin.ignore(); 
    getline(cin, nama);

    cout << "Masukkan Jumlah Orang: "; 
    cin >> jumlah_orang; 
    cin.ignore(); 

    cout << "Masukkan Tanggal (YYYY-MM-DD): "; 
    getline(cin, tanggal);

    cout << "Masukkan Jam (HH:MM): "; 
    getline(cin, jam);

    time_check(no_reservasi, nama, jumlah_orang, tanggal, jam);

    cout << endl;
    cout << "*** Reservasi berhasil dibuat ***" << endl;
    cout << endl;
}
