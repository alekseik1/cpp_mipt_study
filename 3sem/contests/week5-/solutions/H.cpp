//
// Created by aleksei on 03.10.17.
//

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

bool isEqual(const string& s1, const string& s2) {
    for(auto i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i])
            return false;
    }
    return true;
}

int main() {
    string s1 = "";
    string s2 = "";
    getline(cin, s1);
    getline(cin, s2);
    string::size_type l = s1.size();

    stringstream ss;
    ss << s1 << s1;

    s1 = ss.str();

    int res = -1;
    for(string::size_type i=0; i < l; i++) {
        if(isEqual(s1.substr(i, l), s2)) {
            res = i;
            break;
        }
    }
    if(res == -1) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}