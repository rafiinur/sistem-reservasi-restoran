#include <iostream>
#include <string>
#include "header/struct.h"
#include "header/tambah_reservasi.h"

using namespace std;

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

    addReservation(reservasi, {no_reservasi, nama, jumlah_orang, tanggal, jam});
    cout << "Reservasi berhasil dibuat!" << endl;
}
