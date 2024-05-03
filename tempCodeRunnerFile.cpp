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

        cout << d1 << endl;

    }
}


int main ()
{
    show_entry();
}