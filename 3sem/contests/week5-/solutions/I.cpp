#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int levenshtein_distance(const string& src, const string& dst) {

    const int m = src.size();
    const int n = dst.size();

    // Граничные случаи
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    vector<vector<int>> matrix(m + 1);

    for (int i = 0; i <= m; ++i) {
        matrix[i].resize(n + 1);
        matrix[i][0] = i;
    }
    for (int i = 0; i <= n; ++i) {
        matrix[0][i] = i;
    }

    int above_cell, left_cell, diagonal_cell, cost;

    for (int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            cost = ( (src[i - 1] == dst[j - 1]) ? 0 : 1 );
            above_cell = matrix[i - 1][j];
            left_cell = matrix[i][j - 1];
            diagonal_cell = matrix[i - 1][j - 1];
            matrix[i][j] = min(min(above_cell + 1, left_cell + 1), diagonal_cell + cost);
        }
    }

    return matrix[m][n];
}

int main() {
    string s1 = "";
    string s2 = "";
    getline(cin, s1);
    getline(cin, s2);
    auto c = levenshtein_distance(s1, s2);
    cout << c;
}