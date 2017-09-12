#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int a;
    bool isSimple = true;
    cin >> a;
    for(int i = 2; i < (int) (sqrt(a) + 1); i ++) {
        if(a % i == 0) {
            isSimple = false;
            break;
        }
    }
    cout << (isSimple);
    return 0;
}
