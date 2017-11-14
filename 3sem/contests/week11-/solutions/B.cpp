//
// Created by aleksei on 14.11.17.
//

#include <iostream>
#include <vector>
#include <algorithm>

class MyClass {
private:
    std::vector<std::pair<int, std::string>> v;
public:
    void addElement(int i, std::string s) {
        std::pair<int, std::string> tmp_pair;
        tmp_pair = std::make_pair(i, s);
        if(std::find(v.begin(), v.end(), tmp_pair) == v.end()) {    // Не нашли
            v.push_back(tmp_pair);
        }
    }

    void printStructures() {
        for(auto& pair : v) {
            std::cout << pair.first << ' ' << pair.second << std::endl;
        }
    }
};