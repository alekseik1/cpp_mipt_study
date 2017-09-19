//
// Created by aleksei on 19.09.17.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i=0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int& i : a) {
        cout << i << " ";
    }
    return 0;
}