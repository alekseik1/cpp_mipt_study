//
// Created by aleksei on 19.09.17.
//

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i=0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0;
    while(i < n-1) {
      if(a[i] > a[i+1]) {
          int tmp = a[i];
          a[i] = a[i+1];
          a[i+1] = tmp;
          i = 0;
      } else {
          i++;
      }
    }
    for(int& item : a) {
        cout << item << " ";
    }
    //cout << s;
    return 0;
}