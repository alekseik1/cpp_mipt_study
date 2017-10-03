//
// Created by aleksei on 03.10.17.
//

#include <iostream>
#include <algorithm>

using namespace std;

string* move_right(string* s) {
    char tmp = (*s)[0];
    int l = (*s).size();
    for(int i = 0; i < l; i++) {
        (*s)[i] = (*s)[i + 1];
    }
    (*s)[l-1] = tmp;
    return s;
}

int main() {
    string s = "";
    string s1 = "";
    getline(cin, s);
    getline(cin, s1);
    bool found = false;
    string* curr = &s;
    for(unsigned i = 0; i < s.size() - 1; i++) {
        if(*curr == s1) {
            found = true;
            cout << i << endl;
            break;
        }
        curr = move_right(curr);
    }
    if(!found) {
        cout << -1 << endl;
    }

    return 0;
}