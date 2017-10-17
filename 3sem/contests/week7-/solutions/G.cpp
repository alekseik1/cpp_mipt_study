//
// Created by aleksei on 17.10.17.
//
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int MAXN = 10000;
    int INF = 1000000;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int d[MAXN]; // константа MAXN равна наибольшему возможному значению n

    for (int i=0; i<n; ++i) {
        d[i] = 1;
        for (int j=0; j<i; ++j)
            if (a[j] < a[i])
                d[i] = max (d[i], 1 + d[j]);
    }

    int ans = d[0];
    for (int i=0; i<n; ++i)
        ans = max (ans, d[i]);
    cout << ans << endl;
}