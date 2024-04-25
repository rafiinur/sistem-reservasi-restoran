#include <iostream>
#include <string>
#include <fstream>
// #include "tambah.h"
#include "tes.h"

using namespace std;



void daftar_re()
{
    ifstream file("reservasi.csv");

    if(file.fail())
    {
        cout << "Gagal membuka file" << endl;
    }

    string nama, temp, tanggal, jam;
    int jumlah_orang;

    while (!file.eof())
    {
        getline(file, nama, ',');
        getline(file, temp, ',');
        jumlah_orang = atoi(temp.c_str());
        getline(file, tanggal, ',');
        getline(file, jam, '\n');

        cout << "Nama \t\t : " << nama << endl;
        cout << "Jumlah Orang \t : " << jumlah_orang << endl;
        cout << "Tanggal \t : " << tanggal << endl;
        cout << "Jam \t\t : " << jam << endl;
        cout << endl;
    }

}

// int main ()
// {

//     daftar_re();

// }