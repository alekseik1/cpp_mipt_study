//
// Created by aleksei on 19.09.17.
//

#include <iostream>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    m = m%n;
    int a[n];
    for(int i=0; i < n; i++) {
        cin >> a[i];
    }
    for(int i=m; i < n; i++) {
        cout << a[i] << " ";
    }
    for(int i=0; i < m; i++) {
        cout << a[i] << " ";
    }
    return 0;
}