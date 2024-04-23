// Menu Utama

#include <iostream>

using namespace std;

void daftar_pilihan () 
{
    cout<<endl
        << "Pilihan Menu" << endl
        << "1. Daftar Reservasi" << endl
        << "2. Tambah Reservasi" << endl
        << "3. Hapus Reservasi"<< endl
        << "4. Keluar"
        << endl;
}


int main () {
    cout << endl;
    cout << "==========================" << endl;
    cout << "     Selamat Datang" << endl;
    cout << "Sistem Reservasi Restoran" << endl;
    cout << "==========================" << endl;
    cout << endl;

    daftar_pilihan();
    int pilih;

    cout << "Pilihan Anda (Pilih Nomor) : "; cin >> pilih;
    
    while (pilih != 4){
        if (pilih == 1)
        {
            // Modul daftar reservasi
            cout << "1 pass" << endl;
            daftar_pilihan();
            cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
        }

        else if (pilih == 2)
        {
            // modul tambah reservasi
            cout << "2 pass" << endl;
            daftar_pilihan();
            cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
        }

        else if (pilih == 3)
        {
            // modul hapus reservasi
            cout << "3 pass" << endl;
            daftar_pilihan();
            cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
        }
        
    }
   
   cout << "Terima Kasih telah menggunakan sistem ini";
    
}