#include<iostream>
#include<list>

using namespace std;

int findMin(int& a, int& b, int& c) {
    int min_c;
    min_c = min(min(a, b), c);
    //min_c = (c >= b) ? ((b >= a) ? a : b) : c;
    return min_c;
}


int main() {
    int a, b,c;
    cin >> a >> b >> c;
    cout << findMin(a, b, c);
    return 0;
}
