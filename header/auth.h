#ifndef AUTH_H
#define AUTH_H

#include<string>
using namespace std;

void auth(string in_user, string in_pswd);
void login();

extern bool check;
extern string role;


#endif