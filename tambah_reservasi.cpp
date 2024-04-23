#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

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
    reservasi *temp = head;
    while (temp != NULL)
    {
        if (temp->tanggal == tanggal && temp->jam == jam)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
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

    ofstream file("reservasi.csv", ios::app);
    if (file.is_open())
    {
        if (file.tellp() == 0)
        {
            file << "Nama,Jumlah Orang,Tanggal,Jam\n";
        }

        file << nama << "," << jumlah_orang << "," << tanggal << "," << jam << "\n";
        file.close();
    }
    else
    {
        cout << "Unable to open file.\n";
    }
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

int main()
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

    return 0;
}
