#include<iostream>
#include<cmath>
#include<map>
#include<vector>

using namespace std;

int co(int a) {
    int count = 1;
    int step = 0;
    while(a != 1) {
        if(a % 2 == 1) {
            a--;
            step++;
        } else {
            a/=2;
            step++;
        }
    }
    return step;
}

int main() {
    int a; cin >> a;
    cout << co(a) << endl;
    return 0;
}
