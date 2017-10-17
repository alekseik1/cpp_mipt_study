//
// Created by aleksei on 17.10.17.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int i = 0;
    int iter = 0;
    while(i < s.length()){
        if (iter%2==0)
            cout << (char) toupper(s[i]);
        else
            cout << (char) tolower(s[i]);
        if(s[i] != ' ') iter++;
        i++;
    }
    return 0;
}
