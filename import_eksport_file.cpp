#include <iostream>
#include <fstream>
#include <string>
#include "header/struct.h"
#include "header/import_eksport_file.h"
#include "header/tambah_reservasi.h"

using namespace std;

void clearList(Node *&head) {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void importFromFile(Node *&head, const string &filename) {
    ifstream file("data/" + filename);
    if (!file.is_open()) {
        cerr << "Gagal membuka file." << endl;
        return;
    }

    clearList(head); // Hapus semua data sebelum mengimpor dari file

    int no_reservasi;
    string nama;
    int jumlah_orang;
    string tanggal;
    string jam;
    while (file >> no_reservasi >> nama >> jumlah_orang >> tanggal >> jam) {
        addReservation(head, {no_reservasi, nama, jumlah_orang, tanggal, jam});
    }

    file.close();
    cout << "Data reservasi berhasil dimuat dari file." << endl;
}

void exportToFile(Node *head, const string &filename) {
    ofstream file("data/" + filename);
    if (!file.is_open()) {
        cerr << "Gagal membuka file." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        file << current->data->no_reservasi << "," << current->data->nama << "," << current->data->jumlah_orang << "," << current->data->tanggal << "," << current->data->jam << endl;
        current = current->next;
    }

    file.close();
    cout << "Data reservasi berhasil disimpan ke file." << endl;
}