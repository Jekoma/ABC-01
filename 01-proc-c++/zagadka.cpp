// Это структура загадка. Ответ = строка символов
#include "ZAGADKA.h"
#include "rnd.h"

// Чтение входных данных
void In(zagadka& z, ifstream& ifst) {
    //strcpy_s(z.input, strlen(s) + 1, s);
    ifst.getline(z.input, sizeof(z.input));
}

// Получение входных данных через рандомайзер 
void InRnd(zagadka& z) {
    strcpy_s(z.input, 22, Random());
    z.input[9] = ' ';
    z.input[10] = '?';
    z.input[11] = ' ';
}

// Вывод данных
void Out(zagadka& z, ofstream& ofst) {
    ofst << "It is Zagadka, input = ";
    for (int i = 0; i < strlen(z.input); i++) {
        ofst << z.input[i];
    }
    ofst << " CHASTNOE = " << Chastnoe(z) << "   OTVET = " << z.answer << " \n";
    //ofst << "It is Aforizm: str = "        

}

// Получение частного 
double Chastnoe(zagadka& z) {
    double X;
    double count = 0.0, x = 0.0;
    int xx = 0;
    int i = 0;

    do {
        if (z.input[i] == '?') {
            xx++;
        }
        i++;
    } while (xx == 0 && i < sizeof(z.input));
    x = i;
    copy(z.input + i, z.input + strlen(z.input), z.answer);
    for (int i = 0; i < sizeof(z.input); i++) {
        if (z.answer[i] == '.') {
            z.answer[i + 1] = '\0';
            break;
        }
    }
    for (int j = 0; j < strlen(z.answer); j++) {
        if (z.answer[j] == '.' || z.answer[j] == ',' || z.answer[j] == ';' || z.answer[j] == ':' || z.answer[j] == '-' ||
            z.answer[j] == '?' || z.answer[j] == '!' || z.answer[j] == '(' || z.answer[j] == ')' || z.answer[j] == '"' ||
            z.answer[j] == '<' || z.answer[j] == '>' || z.answer[j] == '{' || z.answer[j] == '}') {
            count++;
        }
    }
    X = strlen(z.answer) / count;
    return X;
}