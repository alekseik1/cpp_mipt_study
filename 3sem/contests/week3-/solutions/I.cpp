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
    for(int i=0; i < n-1; i++) {
        // Let's comment it for a better day
        //if(a[i+1] != a[i]) {
            res += a[i+1] - a[i] - 1;
        //}
    }
    cout << res;
    return 0;
}