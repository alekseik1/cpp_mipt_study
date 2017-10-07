//
// Created by aleksei on 03.10.17.
//

#include <iostream>
#include <algorithm>

int main() {
    std::string s = "";
    std::getline(std::cin, s);
    int res = 0;
    for(char& i : s) {  // Для каждого символа в строке
        char k = tolower(i);    // Приводим к нижнему регистру
        std::cout << k;         // Выводим
    }
}