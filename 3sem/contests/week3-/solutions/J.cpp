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
    int res = 0;
    bool pos = true;
    for(int i=0; i < n-1; i++) {
        if(a[i+1] == a[i]) {
            res += 1;
        }
        if(res > 1) {
            pos = false;
            break;
        }
    }
    cout << (pos) ? 1 : 0;
    return 0;
}