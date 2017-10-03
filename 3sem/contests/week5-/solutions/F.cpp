//
// Created by aleksei on 03.10.17.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string s = "";
    getline(cin, s);

    stringstream ss(s);
    string buf;
    vector<string> words;
    while(ss >> buf) {
        words.push_back(buf);
    }
    for(int i = 0; i < words.size(); i++) {
        if(words[i].size() <= 3) {
            words.at(i) = "";
        }
    }
    for(auto& w : words) {
        cout << w << " ";
    }
    return 0;
}