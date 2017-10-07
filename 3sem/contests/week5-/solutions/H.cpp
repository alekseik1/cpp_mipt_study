//
// Created by aleksei on 03.10.17.
//

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

bool isEqual(const string& s1, const string& s2) {  // Проверка, равны ли строки. Я думал, что это ускорит алгоритм (наивный)
    for(auto i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i])
            return false;
    }
    return true;
}

int main() {
    string s1 = "";
    string s2 = "";
    getline(cin, s1);
    getline(cin, s2);
    string::size_type l = s1.size();    // size_type - это тот же int. Не пугайтесь

    stringstream ss;    // Поток, уже проходили это
    ss << s1 << s1;     // В него записываем дважды первую строку

    s1 = ss.str();
    // По сути, здесь первая строка записывается два раза подряд.
    // Идея алгоритма: записать первую строку дважды, затем прогуляться для i от 0 до l (l - длина строки s2, она же длина строки s1).
    // Смотрим подстроку s1 (записанного дважды) с позиции i до (i+l). Если она в точности равна строке s2, то мы нашли, что они являются сдвигом друг друга на i.
    // Если за все итерации такого не получилось, то ответом будет -1

    int res = -1;
    for(string::size_type i=0; i < l; i++) {    // Итерируемся
        if(isEqual(s1.substr(i, l), s2)) {  // Проверка равенств подстрок
            res = i;
            break;  // Нашли i, дальше нет смысла искать
        }
    }

    cout << res << endl;    // Выводим результаты
    return 0;
}