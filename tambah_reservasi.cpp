#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem> 
#include "tambah.h"

using namespace std;
namespace fs = filesystem;

reservasi *head = NULL;
reservasi *tail = NULL;

bool fileExists(const string& filename) {
    return fs::exists(filename);
}

bool isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    return false;   
}

bool isFull(string input_tanggal, string input_jam)
{
    ifstream file("reservasi.csv");
    string line;

    // Mengabaikan baris header
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);
        string no, nama, jumlah, tanggal, jam;

        getline(ss, no, ','); 
        getline(ss, nama, ',');
        getline(ss, jumlah, ','); 
        getline(ss, tanggal, ',');
        getline(ss, jam, ',');

        if (input_tanggal == tanggal && input_jam == jam)
        {
            return true;
        }
    }

    return false;
}

void buat_file(int no_reservasi, string nama, int jumlah_orang, string tanggal, string jam)
{

    if (!fileExists("reservasi.csv")) {
        ofstream createFile("reservasi.csv");
        if (createFile.is_open()) {
            createFile << "no,nama,jumlah orang,tanggal,jam\n";
            createFile.close();
        } else {
            cout << "File gagal dibuat.\n";

        }
    }

    ofstream file("reservasi.csv", ios::app);
    if (file.is_open()) {
        file << no_reservasi << "," << nama << "," << jumlah_orang << "," << tanggal << "," << jam << "\n";
        file.close();
    } else {
        cout << "File gagal dibuka.\n";
    }
}

void tambah_reservasi(int no_reservasi, string nama, int jumlah_orang, string tanggal, string jam)
{
    if (isFull(tanggal, jam))
    {
        cout << "\nMaaf, meja pada tanggal " << tanggal << " jam " << jam << " sudah terisi.\n";
        return;
    }

    reservasi *new_reservasi = new reservasi;
    new_reservasi->no_reservasi = no_reservasi;
    new_reservasi->nama = nama;
    new_reservasi->jumlah_orang = jumlah_orang;
    new_reservasi->tanggal = tanggal;
    new_reservasi->jam = jam;
    new_reservasi->next = NULL;

    if (isEmpty())
    {
        head = new_reservasi;
        tail = new_reservasi;
    }
    else
    {
        tail->next = new_reservasi;
        tail = new_reservasi;
    }

    buat_file(no_reservasi, nama, jumlah_orang, tanggal, jam);

    cout << "\nReservasi berhasil ditambahkan.\n";
}

void lihat_reservasi()
{
    reservasi *current = head;
    int i = 1;
    while (current != NULL)
    {
        cout << i << ". " << current->nama << " - " << current->jumlah_orang << " orang - " << current->tanggal << " - " << current->jam << endl;
        current = current->next;
        i++;
    }
}



// void t_resv()
// {
//     int no_reservasi = 1;
//     string nama;
//     int jumlah_orang;
//     string tanggal;
//     string jam;
//     head = NULL;

//     cout << "==========================" << endl;
//     cout << "     Selamat Datang" << endl;
//     cout << "Sistem Reservasi Restoran" << endl;
//     cout << "==========================" << endl;
//     cout << endl;

//     cout << "\n========Buat Reservasi========" << endl;
//     cout << "Masukkan Nama: "; getline(cin, nama);
//     cout << "Masukkan Jumlah Orang: "; cin >> jumlah_orang; cin.ignore(); 
//     cout << "Masukkan Tanggal (YYYY-MM-DD): "; getline(cin, tanggal);
//     cout << "Masukkan Jam (HH:MM): "; getline(cin, jam);

//     tambah_reservasi(no_reservasi, nama, jumlah_orang, tanggal, jam);

//     cout << "Daftar Reservasi:\n";
//     lihat_reservasi();

// }
