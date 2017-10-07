//
// Created by aleksei on 03.10.17.
//

#include <iostream>

int main() {
    std::string s = "";
    std::getline(std::cin, s);
    int res = 1;
    for(int i = s.size()-1; i >= 0; i--) {
        if(s[i] == ' ') {   // Если есть пробел, значит,у нас новое слово
            res++;
        }
    }
    std::cout << res << "\n";
}