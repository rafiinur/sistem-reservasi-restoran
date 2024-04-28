#include <iostream>
#include <string>
#include "header/struct.h"
#include "header/hapus_reservasi.h"

void removeReservation(Node *&head, int no_reservasi) {
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr) {
        if (current->data->no_reservasi == no_reservasi) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current->data; // Hapus memori yang dialokasikan untuk data
            delete current;
            return;

            cout << "Reservasi berhasil dihapus." << endl;
        }
        prev = current;
        current = current->next;
    }

    cout << "Reservasi tidak ditemukan." << endl;
}
