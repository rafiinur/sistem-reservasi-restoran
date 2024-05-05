#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct show_entry
{
    string nme;
    int jml;
    string tgl;
    string wkt;
    show_entry *next;
};

show_entry *first = nullptr;

bool check()
{
    if (first == nullptr)
    {
        return true;
    }
    return false;
}

void LL_input ()
{
    ifstream file ("reservasi.csv");
    if (file.fail())
    {
        cout << "Gagal membuka file";
        return;
    }

    while (!file.eof())
    {
        show_entry *node;
        node = new show_entry;

        string d1;
        int d2;
        string d3;
        string d4;
        string tmp;
        getline (file, d1, ',');
        getline (file, tmp, ',');
        d2 = atoi(tmp.c_str());
        getline (file, d3, ',');
        getline (file, d4, '\n');

        node ->nme = d1;
        node ->jml = d2;
        node ->tgl = d3;
        node ->wkt = d4;

        if (check())
        {
            first = node;
            first->next = nullptr;
        }
        else
        {
            show_entry *current = first;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = node;
        }

    }
    file.close();
}

void out ()
{
    show_entry *current;
    current = first;

    while(current != nullptr)
    {
        cout << endl
            << "Nama \t \t : " << current->nme << endl
            << "Jumlah Orang \t : " << current->jml << endl
            << "Tanggal \t : " << current->tgl << endl
            << "Waktu \t \t : " << current->wkt << endl;

        current = current->next;
    }
}

int main ()
{
    LL_input();
    out();
}