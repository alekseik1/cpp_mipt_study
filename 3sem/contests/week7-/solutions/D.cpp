#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int X[n][n];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> X[i][j];

    int max = X[0][0], diagMaxIndex = 0;
    for (int i=n-1; i >= 0; i--) {
        if (X[i][i] >= max) {
            max = X[i][i];
            diagMaxIndex = i;
        }
    }

    for (int j=0; j<n; j++){
        //int tmp = 0;
        int tmp = 0;
        tmp = X[diagMaxIndex][j];
        X[diagMaxIndex][j] = X[x][j];
        X[x][j] = tmp;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            cout << X[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}