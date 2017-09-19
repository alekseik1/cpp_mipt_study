//
// Created by aleksei on 19.09.17.
//

#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a;
    for(int i=0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    //int smin, smax;
    sort(a.begin(), a.end());
    cout << (a.at(0) + a.at(1)) << " " << (a.at(a.size()-1)+a.at(a.size()-2));
    return 0;
}