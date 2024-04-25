// #include <iostream>
// #include <string>
// #include "hapus.h"
// #include "tambah.h"

// using namespace std;

// // Hapus reservasi
// void hapus_reservasi(int nomor_reservasi) {
//     reservasi *current = Null;
//     reservasi *prev = NULL;

//     int i = 1;
//     while (current != NULL) {
//         if (i == nomor_reservasi) {
//             if (prev != NULL) {
//                 prev->next = current->next;
//             } else {
//                 head = current->next;
//             }
//             delete current;
//             cout << "Reservasi dengan nomor " << nomor_reservasi << " telah dihapus.\n";
//             return;
//         }
//         prev = current;
//         current = current->next;
//         i++;
//     }
//     cout << "Reservasi dengan nomor " << nomor_reservasi << " tidak ditemukan.\n";
// }

// void resv_hapus() // diganti jadi void untuk dipanggil di header
// {
//     int pilihan;
//     cout << "Masukkan nomor reservasi yang ingin dihapus: ";
//     cin >> pilihan;
//     if (pilihan != 0)
//     {
//         hapus_reservasi(pilihan);
//         cout << "Reservasi setelah dihapus:\n";
//     }

// }
