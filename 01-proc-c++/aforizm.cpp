// Это структура афоризм. Автор = строка символов
#include "AFORIZM.h"
#include "rnd.h"


// Чтение данных из файла
void In(aforizm& a, ifstream& ifst) {
    ifst.getline(a.input, sizeof(a.input));
}

// Получение рандомных данных
void InRnd(aforizm& a) {
    strcpy_s(a.input, 22, Random());
    a.input[9] = ' ';
    a.input[10] = '|';
    a.input[11] = ' ';
}

// Вывод в файл
void Out(aforizm& a, ofstream& ofst) {
    ofst << "It is Aforizm, input = ";
    for (int i = 0; i < strlen(a.input); i++) {
        ofst << a.input[i];
    }
    ofst << " CHASTNOE = " << Chastnoe(a) << "   AVTOR = " << a.answer << " \n"; 
}

// Вычисление частного
double Chastnoe(aforizm& a) {
    double X;
    double count = 0.0, x = 0.0;
    int xx = 0;
    int i = 0;

    do {
        if (a.input[i] == '|') {
            xx++;
        }
        i++;
    } while (xx == 0 && i < sizeof(a.input));
    x = i;

    copy(a.input + i, a.input + strlen(a.input), a.answer);
    for (int i = 0; i < sizeof(a.answer); i++) {
        if (a.answer[i] == '.') {
            a.answer[i + 1] = '\0';
            break;
        }
    }
    for (int j = 0; j < strlen(a.answer); j++) {
        if (a.answer[j] == '.' || a.answer[j] == ',' || a.answer[j] == ';' || a.answer[j] == ':' || a.answer[j] == '-' ||
            a.answer[j] == '?' || a.answer[j] == '!' || a.answer[j] == '(' || a.answer[j] == ')' || a.answer[j] == '"' ||
            a.answer[j] == '<' || a.answer[j] == '>' || a.answer[j] == '{' || a.answer[j] == '}') {
            count++;
        }
    }
    X = strlen(a.answer) / count;
    return X;
}
