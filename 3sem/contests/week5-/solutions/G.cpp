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
    for(char& c : s) {
        if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
            curr += c;
        else {
            max_n = std::atoi(curr.c_str());
            if (max_n >= max) {
                max = max_n;
            }
            curr.erase(curr.begin(), curr.end());
        }
    }
    cout << max << endl;
    return 0;
}