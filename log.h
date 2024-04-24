#ifndef LOG_H
#define LOG_H

#include<string>
using namespace std;

void log(string in_user, string in_pswd);
void login();

extern bool check;
extern string role;


#endif