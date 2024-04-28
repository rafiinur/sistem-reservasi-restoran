#include <iostream>
#include "header/list_reservasi.h"

void displayReservations(Node *head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Nomor Reservasi: " << current->data->no_reservasi << ", Nama: " << current->data->nama << ", Jumlah Orang: " << current->data->jumlah_orang << ", Tanggal: " << current->data->tanggal << ", Jam: " << current->data->jam << std::endl;
        current = current->next;
    }
}
