#ifndef STRUCT_H
#define STRUCT_H

#include <string>
using namespace std;

struct Reservasi {
    int no_reservasi;
    string nama;
    int jumlah_orang;
    string tanggal;
    string jam;
};

struct Node {
    Reservasi *data;
    Node *next;
};

extern Node *reservasi;

#endif
