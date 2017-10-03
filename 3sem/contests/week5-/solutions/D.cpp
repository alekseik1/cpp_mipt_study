//
// Created by aleksei on 03.10.17.
//

#include <iostream>
#include <algorithm>

int main() {
    std::string s = "";
    std::getline(std::cin, s);
    int res = 0;
    for(char& i : s) {
        res++;
        std::cout << i;
        if(res % 5 == 0) {
            std::cout << " ";
        }
    }
}