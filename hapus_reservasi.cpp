#include <iostream>
#include <string>
#include "hapus.h"

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

reservasi *head = NULL;
reservasi *tail = NULL;

// Hapus reservasi
void hapus_reservasi(int no_reservasi) {
    reservasi *current = head;

    while (current != NULL) {
        if (current->no_reservasi == no_reservasi) {
            if (current == head && current == tail) {
                // Jika ini adalah satu-satunya node dalam linked list
                head = NULL;
                tail = NULL;
            } else if (current == head) {
                // Jika ini adalah node pertama dalam linked list
                head = current->next;
                head->prev = NULL;
            } else if (current == tail) {
                // Jika ini adalah node terakhir dalam linked list
                tail = current->prev;
                tail->next = NULL;
            } else {
                // Jika ini adalah node di tengah linked list
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            cout << "Reservasi dengan nomor " << no_reservasi << " telah dihapus.\n";
            return;
        }
        current = current->next;
    }
    cout << "Reservasi dengan nomor " << no_reservasi << " tidak ditemukan.\n";
}

void resv_hapus() // diganti jadi void untuk dipanggil di header
{
    int pilihan;
    cout << "Masukkan nomor reservasi yang ingin dihapus: ";
    cin >> pilihan;
    if (pilihan != 0)
    {
        hapus_reservasi(pilihan);
        cout << "Reservasi setelah dihapus:\n";
    }

}
