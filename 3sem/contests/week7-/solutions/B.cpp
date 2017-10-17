#include <iostream>
using namespace std;

int main()
{
    int n, properNumbers = 1, x, firstDigit;
    cin >> n;
    bool totallyBad, check4, check7, check9;
    for (int i=0; i<n; i++){
        cin >> x;
        firstDigit = x/1000;
        check4 = (x%4==0) && (firstDigit!=4) && (firstDigit!=5);
        check7 = (x%7==0) && (firstDigit!=7) && (firstDigit!=1);
        check9 = (x%9==0) && (firstDigit!=8) && (firstDigit!=9);
        totallyBad = check4 || check7 || check9;
        if (totallyBad){
            properNumbers = 0;
            cout << x << ' ';
        }
    }
    if(properNumbers)
        cout << 0;

    return 0;
}