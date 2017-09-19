//
// Created by aleksei on 19.09.17.
//

#include <iostream>
#include<cmath>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(2);
    bool isDiv = false;
    for(int i=3; i <= n; i++) {
        for(int& c : a) {
            if(i % c == 0) {
                isDiv = true;
            }
        }
        if(!isDiv) a.push_back(i);
        isDiv = false;
    }
    for(auto& item : a) {
        cout << item << " ";
    }
    return 0;
}