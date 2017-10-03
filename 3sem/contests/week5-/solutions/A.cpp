//
// Created by aleksei on 03.10.17.
//

#include <iostream>

int main() {
    std::string s = "";
    std::getline(std::cin, s);
    for(int i = s.size()-1; i >= 0; i--) {
        std::cout << s[i];
    }
    std::cout << "\n";
}