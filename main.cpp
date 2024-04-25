// Menu Utama

#include <iostream>
#include "log.h"
#include "tambah.h"
#include "hapus.h"
#include "tes.h"

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

    //Header login
    login();

    if (check)
    {
        cout << endl;
        cout << "==========================" << endl;
        cout << "     Selamat Datang" << endl;
        cout << "Sistem Reservasi Restoran" << endl;
        cout << "==========================" << endl;
        cout << endl;

        daftar_pilihan();
        int pilih;

        cout << "Pilihan Anda (Pilih Nomor) : "; cin >> pilih;
    
        while (pilih != 4)
        {
            if (pilih == 1)
            {
                // Modul daftar reservasi
                daftar_re();
                daftar_pilihan();
                cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
            }

            else if (pilih == 2)
            {
                int no_reservasi = 1;
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
                cout << "Masukkan Nama: "; getline(cin, nama); cin.ignore(); 
                cout << "Masukkan Jumlah Orang: "; cin >> jumlah_orang; 
                cout << "Masukkan Tanggal (YYYY-MM-DD): "; getline(cin, tanggal);
                cout << "Masukkan Jam (HH:MM): "; getline(cin, jam);

                tambah_reservasi(no_reservasi, nama, jumlah_orang, tanggal, jam);

                cout << "Daftar Reservasi:\n";
                lihat_reservasi();

                cout <<endl;
                daftar_pilihan();
                cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
            }

            else if (pilih == 3)
            {
                // modul hapus reservasi
                if (role != "admin")
                {
                    cout << "====================================" << endl;
                    cout << "Maaf Anda tidak punya akses" << endl;
                    cout << "Silahkan Pilih nomor yang lain";
                    cout << "====================================" << endl;
                    daftar_pilihan();
                    cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
                    
                }

                else 
                {
                    resv_hapus();
                    cout << "3 pass" << endl;
                    daftar_pilihan();
                    cout << "Silahkan pilih kembali nomor Anda : "; cin >> pilih;
                }
                
            }
        
        }
   
            cout << "Terima Kasih telah menggunakan sistem ini";
    }
  
}