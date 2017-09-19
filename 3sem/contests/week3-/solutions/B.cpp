//
// Created by aleksei on 19.09.17.
//

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i=0; i < n; i++) {
        cin >> a[i];
    }
    int s = 0;
    for(int i=0; i < n; i++) {
        if(i%21 == 0) s += a[i];
    }
    cout << s;
    return 0;
}