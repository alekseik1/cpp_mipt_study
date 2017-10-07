//
// Created by aleksei on 03.10.17.
//

#include <iostream>

int main() {
    std::string s = "";
    std::getline(std::cin, s);
    int res = 0;
    for(char& i : s) {
        if(i == '2' || i == '0' || i == '4' || i == '6' || i == '8') {  // Если встречаем один из нужных символов, то прибавляем счетчик
            res++;
        }
    }
    std::cout << res << "\n";
}