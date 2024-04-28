#include <iostream>
#include "header/list_reservasi.h"

using namespace std;

void displayReservations(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << "Daftar Reservasi : " << endl;
        cout << endl;
        cout << "-------------------------" << endl;
        cout << "Nomor Reservasi : " << current->data->no_reservasi << endl;
        cout << "Nama : " << current->data->nama << endl; 
        cout << "Jumlah Orang : " << current->data->jumlah_orang << endl;
        cout << "Tanggal : " << current->data->tanggal << endl;
        cout << "Jam : " << current->data->jam << endl;
        cout << "-------------------------" << endl;
        cout << endl;
        current = current->next;
    }
}
