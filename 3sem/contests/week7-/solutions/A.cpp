#include <iostream>
using namespace std;

int main()
{
    float n;
    cin >> n;
    while(n>=2)
        n = n/2.;

    if (n==1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}