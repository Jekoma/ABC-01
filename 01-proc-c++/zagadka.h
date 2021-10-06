#ifndef __ZAGADKA__
#define __ZAGADKA__
//------------------------------------------------------------------------------
//содержит описание загадки
//------------------------------------------------------------------------------
#include <fstream>
using namespace std;

struct zagadka {
    char  input[10000];// Входная строка
    char  answer[10000];// Ответ
};



void In(zagadka& z, ifstream& ifst);

void InRnd(zagadka& z);

void Out(zagadka& z, ofstream& ofst);

double Chastnoe(zagadka& z);
#endif