#ifndef __WISDOM__
#define __WISDOM__
#include "zagadka.h"
#include "poslovica.h"
#include "aforizm.h"


//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся строки
struct wisdom {
    // значения ключей для каждой из строк
    enum key { AFORIZM, POSLOVICA, ZAGADKA };
    key k;
    // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию]        
        aforizm a;
        poslovica p;
        zagadka z;
    };

};

//Ввод мудрости
wisdom* In(ifstream& ifdt);

// Случайный ввод мудрости
wisdom* InRnd();

// Вывод мудрости
void Out(wisdom& w, ofstream& ofst);

// Вычисление частного
double Chastnoe(wisdom& w);

#endif
