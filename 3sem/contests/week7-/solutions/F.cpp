//
// Created by aleksei on 17.10.17.
//
#include <iostream>

using namespace std;

int Search_Binary (int arr[], int left, int right, int key)
{
    int midd = 0;
    while (1)
    {
        midd = (left + right) / 2;

        if (key < arr[midd])
            right = midd - 1;
        else if (key > arr[midd])
            left = midd + 1;
        else
            return midd;

        if (left > right)
            return -1;
    }
}

int main() {
    int N, x;
    cin >> N >> x;
    int k[N];
    for(int i = 0; i < N; i++) {
        cin >> k[i];
    }
    int pos = Search_Binary(k, 0, N, x);
    cout << ((pos == -1) ? -1 : pos + 1);
}