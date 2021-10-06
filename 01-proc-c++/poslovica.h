#ifndef __poslovica__
#define __poslovica__
//------------------------------------------------------------------------------
//содержит описание пословицы
//------------------------------------------------------------------------------
#include <fstream>
using namespace std;

struct poslovica {
    char  input[10000]; // Входная строка
    char  answer[10000]; // Страна
};



void In(poslovica& p, ifstream& ifst);

void InRnd(poslovica& p);

void Out(poslovica& p, ofstream& ofst);

double Chastnoe(poslovica& p);
#endif //__poslovica__