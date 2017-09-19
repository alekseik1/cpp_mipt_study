//
// Created by aleksei on 19.09.17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    int a[4];
    vector<int> res;
    a[0] = n / 1000;
    a[1] = (n/100)%10;
    a[2] = (n%100)/10;
    a[3] = n % 10;
    sort(begin(a), end(a));
    int zeros = 0;
    for(int& k : a) {
        if(k == 0) zeros++;
    }
    bool isZeros = false;
    for(int& k : a) {
        if(k != 0) {
            cout << k;
            if(!isZeros) {
                for (int i = 0; i < zeros; i++) {
                    cout << 0;
                }
                isZeros = true;
            }
        }
    }
    return 0;
}