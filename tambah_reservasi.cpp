#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem> 
#include "tambah.h"

using namespace std;
namespace fs = filesystem;


struct reservasi
{
    string nama;
    int jumlah_orang;
    string tanggal;
    string jam;
    reservasi *next;
};

reservasi *head;
reservasi *tail;

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

bool isFull(string tanggal, string jam)
{
    ifstream file("reservasi.csv");
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string nama, tgl, jamm;
        int jumlah;

        getline(ss, nama, ',');
        ss >> jumlah;
        ss.ignore();
        getline(ss, tgl, ',');
        getline(ss, jamm, ',');

        if (tgl == tanggal && jamm == jam)
        {
            file.close();
            return true; 
        }
    }

    file.close();
    return false; 
}

void buat_file(string nama, int jumlah_orang, string tanggal, string jam)
{

    if (!fileExists("reservasi.csv")) {
        ofstream createFile("reservasi.csv");
        if (createFile.is_open()) {
            createFile << "Nama,Jumlah Orang,Tanggal,Jam\n";
            createFile.close();
        } else {
            cout << "Unable to create file.\n";

        }
    }

    ofstream file("reservasi.csv", ios::app);
    if (file.is_open()) {
        file << nama << "," << jumlah_orang << "," << tanggal << "," << jam << "\n";
        file.close();
    } else {
        cout << "Unable to open file.\n";
    }
}

void tambah_reservasi(string nama, int jumlah_orang, string tanggal, string jam)
{
    if (isFull(tanggal, jam))
    {
        cout << "Maaf, meja pada tanggal " << tanggal << " jam " << jam << " sudah terisi.\n";
        return;
    }

    reservasi *new_reservasi = new reservasi;
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

    buat_file(nama, jumlah_orang, tanggal, jam);

    // ofstream file("reservasi.csv", ios::app);
    // if (file.is_open())
    // {
    //     if (file.tellp() == 0)
    //     {
    //         file << "Nama,Jumlah Orang,Tanggal,Jam\n";
    //     }

    //     file << nama << "," << jumlah_orang << "," << tanggal << "," << jam << "\n";
    //     file.close();
    // }
    // else
    // {
    //     cout << "Unable to open file.\n";
    // }

}

void daftar_reservasi()
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

void tambah_resv()
{
    string nama;
    int jumlah_orang;
    string tanggal;
    string jam;
    head = NULL;

    cout << "==========================" << endl;
    cout << "     Selamat Datang" << endl;
    cout << "Sistem Reservasi Restoran" << endl;
    cout << "==========================" << endl;
    cout << endl;

    cout << "========Buat Reservasi========" << endl;
    cout << "Masukkan Nama: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nama);
    cout << "Masukkan Jumlah Orang: ";
    cin >> jumlah_orang;
    cin.ignore(); 
    cout << "Masukkan Tanggal (YYYY-MM-DD): ";
    getline(cin, tanggal);
    cout << "Masukkan Jam (HH:MM): ";
    getline(cin, jam);

    tambah_reservasi(nama, jumlah_orang, tanggal, jam);

    cout << "Daftar Reservasi:\n";
    daftar_reservasi();

}
