#ifndef IMPORT_RESERVASI_H
#define IMPORT_RESERVASI_H

#include <string>
using namespace std;

void importFromFile(Node *&head, const string &filename);
void exportToFile(Node *head, const string &filename);

#endif