//
// Created by aleksei on 03.10.17.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string s = "";
    getline(cin, s);

    stringstream ss(s); // Поток, состоящий из нашей строки. Наша строка - это совокупность слов
    string buf;
    vector<string> words;   // Массив из строк, но на стероидах
    while(ss >> buf) {  // Магия. Для каждого СЛОВА из потока мы кидаем его в вектор (массив) words
        words.push_back(buf);
    }
    for(int i = 0; i < words.size(); i++) { // Для каждого слова
        if(words[i].size() <= 3) {          // Если его длина <= 3
            words.at(i) = "";               // Заменяем его на пустоту
        }
    }                                       // Итого: в векторе лежат слова с длиной > 3
    for(auto& w : words) {                  // Для каждого слова из вектора words
        cout << w << " ";                   // Выводим его
    }
    return 0;
}