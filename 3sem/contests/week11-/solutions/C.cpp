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
    const std::vector<std::pair<int, std::string>> &getV() const {
        return v;
    }

public:

    void addElement(const std::pair<int, std::string> &tmp_pair) {
        if(std::find(v.begin(), v.end(), tmp_pair) == v.end()) {    // Не нашли
            v.push_back(tmp_pair);
        }
    }

    void addElement(int i, const std::string& s) {
        std::pair<int, std::string> tmp_pair;
        tmp_pair = std::make_pair(i, s);
        addElement(tmp_pair);
    }

    void printStructures() {
        for(auto& pair : v) {
            std::cout << pair.first << ' ' << pair.second << std::endl;
        }
    }

    MyClass& operator+=(const MyClass& c2) {
        for(auto& pair : c2.getV()) {
            this->addElement(pair.first, pair.second);
        }
    }
};