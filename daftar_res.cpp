#include <iostream>
#include <string>
#include <fstream>
#include "tambah.h"

using namespace std;

reservasi *head = nullptr;
reservasi *tail = nullptr;



bool is_empty()
{
    if (head == nullptr)
    {
        return true;
    }
    return false;
}

  
void r_w_csv() 
{
    ifstream file("reservasi.csv");


    if (file.is_open())
    {
        string nama, temp, tanggal, jam;
        int jumlah_orang;

        while (file.eof()) 
        {
            getline(file, nama, ',');
            getline(file, temp, ',');
            jumlah_orang = atoi(temp.c_str());
            getline(file, tanggal, ',');
            getline(file, jam, '\n');
            cout << "Nama \t" << nama << endl;

            reservasi* daftar_resf = new reservasi;
            daftar_resf->nama = nama;
            daftar_resf->jumlah_orang = stoi(temp);
            daftar_resf->tanggal = tanggal;
            daftar_resf->jam = jam;
            daftar_resf->next = nullptr;

            if (head == nullptr) 
            {
                head = daftar_resf;
                tail = daftar_resf;
            } 
            else 
            {
                tail->next = daftar_resf;
                tail = daftar_resf;
            }
        }

        file.close();
    }    
    else if (file.fail()) 
    {
        cout << "Gagal membuka file";
    }
    
}

void out_daftar() {
    reservasi* currt = head;
    while (currt != nullptr) {
        cout << "Nama \t" << currt->nama << endl;
        cout << "Jumlah Orang \t" << currt->jumlah_orang << endl;
        cout << "Tanggal \t" << currt->tanggal << endl;
        cout << "Jam \t" << currt->jam << endl;
        currt = currt->next;
    }
}



void daftar_re ()
{
    ifstream file("reservasi.csv");

    if(file.fail())
    {
        cout << "Gagal membuka file" << endl;
    }

    string nama, temp, tanggal, jam;
    int jumlah_orang;

    while (file.eof())
    {
        getline(file, nama, ',');
        getline(file, temp, ',');
        jumlah_orang = atoi(temp.c_str());
        getline(file, tanggal, ',');
        getline(file, jam, '\n');
    }

}

int main ()
{
    r_w_csv();
    out_daftar();

}