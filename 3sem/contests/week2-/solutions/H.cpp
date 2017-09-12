#include<iostream>
#include<cmath>
#include<map>
#include<vector>

using namespace std;

int main() {
    int a; cin >> a;
    int x = 0;
    int y = 0;
    vector<vector<int>> p1;
    vector<vector<int>> p2;
    vector<vector<int>> p3;
    vector<vector<int>> p4;
    for(int i = 0; i < a; i++) {
        cin >> x >> y;
        if(x > 0) {
            if(y > 0) {
                p1.push_back({x, y});
            } else if(y < 0) {
                p4.push_back({x, y});
            }
        } else if(x < 0) {
            if(y > 0) {
                p2.push_back({x, y});
            } else if(y < 0) {
                p3.push_back({x, y});
            }
        }
    }
    int m = max( max( max(p1.size(), p2.size() ), p3.size() ), p4.size() );
    if(p1.size() == m) {
        cout << "1" << " ";
    } else if(p2.size() == m) {
        cout << "2" << " ";
    } else if(p3.size() == m) {
        cout << "3" << " ";
    } else if(p4.size() == m) {
        cout << "4" << " ";
    }
    cout << m << endl;
    return 0;
}
