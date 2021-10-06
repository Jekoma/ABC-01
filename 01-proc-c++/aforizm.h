#ifndef __aforizm__
#define __aforizm__
//------------------------------------------------------------------------------
// содержит описание афоризма
//------------------------------------------------------------------------------
#include <fstream>
using namespace std;

struct aforizm {
    char  input[10000]; // Входная строка
    char  answer[10000]; // Автор
};



void In(aforizm& a, ifstream& ifst);

void InRnd(aforizm& a);

void Out(aforizm& a, ofstream& ofst);

double Chastnoe(aforizm& a);

#endif //__aforizm__
