//
// Created by aleksei on 03.10.17.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    std::string s = "";
    std::getline(std::cin, s);
    int max = 0;
    long max_n = 0;
    string curr = "";
    s += ' ';
    for(char& c : s) {  // Идея: бегаем по символам и записываем их друг за другом до тех пор, пока они - символы цифр. Ну, и ищем максимум
        if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
            curr += c;  // Если символ есть символ цифры, приписываем в конец
        else {          // Иначе
            max_n = std::atoi(curr.c_str());    // Приводим получившуюся последовательность к int
            if (max_n >= max) {             // Обновляем максимум
                max = max_n;
            }
            curr.erase(curr.begin(), curr.end());   // Очищаем переменную для нового подсчета
        }
    }
    cout << max << endl;
    return 0;
}