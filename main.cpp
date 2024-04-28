#include <iostream>
#include <string>
#include "header/auth.h"
#include "header/struct.h"
#include "header/tambah_reservasi.h"
#include "header/list_reservasi.h"
#include "header/hapus_reservasi.h"
#include "header/import_eksport_file.h"

using namespace std;

Node *reservasi = nullptr; // Inisialisasi variabel global

void showMenu() {
    string menu[] = {
        "Daftar Reservasi",
        "Tambah Reservasi",
        "Hapus Reservasi",
        "Eksport Reservasi",
        "Import Reservasi",
        "Keluar"
    };

    cout << "Pilihan Menu" << endl;
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); ++i) {
        cout << i + 1 << ". " << menu[i] << endl;
    }
}

int main () {
    login();

    if (check) {
        int pilih;

        cout << endl;
        cout << "==========================" << endl;
        cout << "      Selamat Datang      " << endl;
        cout << "Sistem Reservasi Restoran" << endl;
        cout << "==========================" << endl;
        cout << endl;

        showMenu();

        cout << "Pilihan Anda (Pilih Nomor) : "; cin >> pilih;
        cout << endl;

        while (pilih != 6) {
            if (pilih == 1) {
                displayReservations(reservasi);
                showMenu();
                cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
                cout << endl;
            }
            else if (pilih == 2) {         
                createReservation();   
                showMenu();
                cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
                cout << endl;
            }
            else if (pilih == 3) {
                if (role != "admin") {
                    cout << "====================================" << endl;
                    cout << "Maaf Anda tidak punya akses" << endl;
                    cout << "Silahkan Pilih nomor yang lain";
                    cout << "====================================" << endl;
                    showMenu();
                    cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
                    cout << endl;
                }
                else {
                    int no_reservasi;

                    cout << "Masukkan nomor reservasi yang ingin dihapus : ";
                    cin >> no_reservasi;

                    removeReservation(reservasi, no_reservasi);

                    showMenu();
                    cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
                    cout << endl;
                }
            }
            else if (pilih == 4) {
                exportToFile(reservasi, "reservasi.csv");
                showMenu();
                cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
                cout << endl;
            }
            else if (pilih == 5) {
                importFromFile(reservasi, "reservasi.csv");
                showMenu();
                cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
                cout << endl;
            }
            else {
                cout << "Pilihan tidak valid" << endl;
                showMenu();
                cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
                cout << endl;
            }
        }
        cout << "Terima Kasih telah menggunakan sistem ini";
    }
}
