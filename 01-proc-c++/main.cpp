// Lin.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <fstream>
#include <stdlib.h> // для функций rand() и srand()
#include <time.h>   // для функции time()
#include "AFORIZM.h"
#include "POSLOVICA.h"
#include "ZAGADKA.h"
#include "WISDOM.h"
#include "container.h"


int main(int argc, char* argv[])
{

    // Проверка на входные данные
    if (argc != 5) {
        cout << "Wrong input! argc != 5";
        return 1;
    }
    // Старт программы 
    cout << "Start \n" << endl;
    container c;
    Init(c);

    // Входные данные = текстовый файл
    if (!strcmp(argv[1], "-tests")) {
        ifstream ifst(argv[2]);
        In(c, ifst);
    }
    // Входные данные = через рандомайзер
    else if (!strcmp(argv[1], "-random")) {

        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            cout << "incorrect numer of strings = "
                << size
                << ". Set 1 <= number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        
        InRnd(c, size); 
    }
    else {
        cout << " you need to put: task01.exe -random number outfile1 outfile2  or task01.exe -tests inputfile outfile1 outfile2";
        return 2;
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";    
    Out(c, ofst1);

    // 2я часть задания
    ofstream ofst2(argv[4]);
    Selection(c, ofst2);
    
    //очистка контейнера
    Clear(c);
    cout << "Stop" << endl;
    return 0;    
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

