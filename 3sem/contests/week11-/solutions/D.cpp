//
// Created by aleksei on 14.11.17.
//
#include <map>
#include <iostream>

// TODO: CHEATING!!! Я использую словарь для этих целей. Зачем усложнять?
class FrequencyTree {
private:
    std::map<int, int> ft;
public:
    void addValue(int i) {
        ft[i]++;
    }

    void printValues() {
        for(auto& iter : ft) {
            std::cout << iter.first << ' ' << iter.second << std::endl;
        }
    }
};