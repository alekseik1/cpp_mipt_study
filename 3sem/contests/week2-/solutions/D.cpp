#include<iostream>
#include<list>

using namespace std;

int main() {
    int a;
    cin >> a;
    int tmp_min, curr;
    cin >> tmp_min;
    int tmp_count = 1;
    for(int i = 1; i < a; i++) {
        cin >> curr;
        if(curr < tmp_min) {
            tmp_min = curr;
            tmp_count = 1;
        } else if(curr == tmp_min) {
            tmp_count++;
        }
    }
    cout << tmp_min << " " << tmp_count << endl;
    return 0;
}
