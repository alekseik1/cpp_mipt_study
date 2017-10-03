#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string::size_type levenshtein_distance(const string & src, const string & dst) {

    const string::size_type m = src.size();
    const string::size_type n = dst.size();

    // Граничные случаи
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    vector<vector<string::size_type>> matrix(m + 1);

    for (string::size_type i = 0; i <= m; ++i) {
        matrix[i].resize(n + 1);
        matrix[i][0] = i;
    }
    for (string::size_type i = 0; i <= n; ++i) {
        matrix[0][i] = i;
    }

    string::size_type above_cell, left_cell, diagonal_cell, cost;

    for (string::size_type i = 1; i <= m; ++i) {
        for(string::size_type j = 1; j <= n; ++j) {
            cost = src[i - 1] == dst[j - 1] ? 0 : 1;
            above_cell = matrix[i - 1][j];
            left_cell = matrix[i][j - 1];
            diagonal_cell = matrix[i - 1][j - 1];
            matrix[i][j] = std::min(std::min(above_cell + 1, left_cell + 1), diagonal_cell + cost);
        }
    }

    return matrix[m][n];
}

int main() {
    std::string s1 = "";
    std::string s2 = "";
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);
    auto c = levenshtein_distance(s1, s2);
    std::cout << c;
}