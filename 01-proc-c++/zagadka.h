#ifndef __ZAGADKA__
#define __ZAGADKA__
//------------------------------------------------------------------------------
//�������� �������� �������
//------------------------------------------------------------------------------
#include <fstream>
using namespace std;

struct zagadka {
    char  input[10000];// ������� ������
    char  answer[10000];// �����
};



void In(zagadka& z, ifstream& ifst);

void InRnd(zagadka& z);

void Out(zagadka& z, ofstream& ofst);

double Chastnoe(zagadka& z);
#endif