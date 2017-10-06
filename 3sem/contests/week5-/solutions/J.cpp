//
// Created by aleksei on 03.10.17.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s = "";
    getline(cin, s);
    int n = s.size();

    int max = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(s[i+j] != s[i-j]) {
                break;
            } else{
                max++;
            }
        }
        cout << 2*max-1 << " ";
        max = 0;
    }
    return 0;
}