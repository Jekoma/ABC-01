//------------------------------------------------------------------------------
// содержит процедуры связанные с обработкой обобщенной мудрости
// и создания произвольных строк
//------------------------------------------------------------------------------
#include "wisdom.h"




wisdom* In(ifstream& ifst) {
	wisdom* wm;	
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		wm = new wisdom;
		wm->k = wisdom::AFORIZM;  // Афоризм
		In(wm->a, ifst);
		return wm;
	case 2:
		wm = new wisdom;
		wm->k = wisdom::POSLOVICA;  // Пословицa
		In(wm->p, ifst);
		return wm;
	case 3:
		wm = new wisdom;
		wm->k = wisdom::ZAGADKA; // Загадка
		In(wm->z, ifst);
		return wm;
	default:
		return 0;
	}
}

//Случайный ввод мудрости
wisdom* InRnd() {
	wisdom* wm;
	auto k = rand() % 3 + 1;
	switch (k) {
	case 1:		
		wm = new wisdom;
		wm->k = wisdom::AFORIZM;
		InRnd(wm->a);		
		return wm;
		
	case 2:		
		wm = new wisdom;
		wm->k = wisdom::POSLOVICA;
		InRnd(wm->p);
		return wm;
		
	case 3:		
		wm = new wisdom;
		wm->k = wisdom::ZAGADKA;
		InRnd(wm->z);
		return wm;
		
	default:		
		return 0;
	}
}

//------------------------------------------------------------------------------*/
// Вывод параметров текущей мудрости
void Out(wisdom& w, ofstream& ofst) {	
	switch (w.k) {		
	case wisdom::AFORIZM:		
		Out(w.a, ofst);
		break;
	case wisdom::POSLOVICA:
		Out(w.p, ofst);
		break;
	case wisdom::ZAGADKA:
		Out(w.z, ofst);
		break;
	default:
		ofst << "Incorrect String!" << endl;
	}
}

//-------
//Вычисление частного

double Chastnoe(wisdom& w) {
	switch (w.k) {
	case wisdom::AFORIZM:
		return Chastnoe(w.a);
		break;
	case wisdom::POSLOVICA:
		return Chastnoe(w.p);
		break;
	case wisdom::ZAGADKA:
		return Chastnoe(w.z);
		break;
	default:
		return 0.0;
	}
}
