#include <iostream>
#include <fstream>
#include <string>
#include "log.h"
using namespace std;

bool check = false;
string role;


void log(string in_user, string in_pswd)
{
    ifstream file("log.csv");

    if (file.is_open())
    {
        string user;
        string pswd;
        

        while (!file.eof())
        {      
            getline(file, user, ',');      
            getline(file, pswd);

            if (in_user == user && in_pswd == pswd)
            {
                check = true;
                // cout << "berhasil masuk";

                if (user == "admin")
                {
                    role = "admin";
                    // cout << "anda admin";
                }
            }
       
        }
        
        if (!check) 
        {
            cout << "Gagal login";
        }
        file.close();
    }
    else 
    {
        cout << "Gagal buka CSV";
    }
}


void siup (string s_user, string s_pswd)
{
    ofstream file("log.csv", ios::app);

    if (!file.is_open()) {
        cout << "Gagal membuka file" << endl;
        return;
    }

    file << "\n" << s_user << "," << s_pswd;
    file.close();

    cout << "Akun Anda telah Didaftarkan" << endl;
    login();
}


void login() 
{
    string inp_user;
    string inp_pswd;
    int pilih;

    cout << endl;
    cout << "==========================" << endl;
    cout << "     Login & Sign Up" << endl;
    cout << "Sistem Reservasi Restoran" << endl;
    cout << "==========================" << endl;
    cout << endl;

    cout << endl;
    cout << "Silahkan Pilih | Login (1) | atau | Signup (2) |" << endl 
    << "Pilihan anda : ";
    cin >> pilih;

    if (pilih == 1)
    {
        cout << "========== Login ==========" << endl;
        cout << "Masukan Username : ";
        cin >> inp_user;

        cout << "Masukan Password : ";
        cin >> inp_pswd;
    
        log(inp_user, inp_pswd);

    }
    
    else if (pilih == 2)
    {
        cout << "========= Sign Up =========" << endl;
        cout << "Masukan Username : ";
        cin >> inp_user;

        cout << "Masukan Password : ";
        cin >> inp_pswd;

        siup(inp_user, inp_pswd);
    }
    
}


