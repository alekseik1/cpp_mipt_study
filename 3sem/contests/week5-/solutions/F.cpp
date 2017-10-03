//
// Created by aleksei on 03.10.17.
//

#include <iostream>
#include <algorithm>

int main() {
    std::string s = "";
    std::getline(std::cin, s);
    std::size_t f1 = s.find(' ');
    std::size_t f2 = s.find(' ', f1);
    while(true) {
        if(f2 - f1 <= 3) {
            s.erase(f1, f2);
        }
        f1 = s.find(' ', f2);
        if(f1 == std::string::npos) break;
        f2 = s.find(' ', f1);
    }
    std::cout << s;
    return 0;
}