#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// СКАТАНО. Взял с вики, но подправил. Уж больно там было нечитаемо
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

    // Матрица стоимости перехода. Надеюсь, все помнят алгоритм для расстояния Левенштейна :)
    vector<vector<int>> matrix(m + 1);

    for (int i = 0; i <= m; ++i) {
        matrix[i].resize(n + 1);    // Делаем массив двумерным: каждый его элемент - это строка
        matrix[i][0] = i;           // И по краям запоняем числами 1234...., как и положено в алгоритме
    }
    for (int i = 0; i <= n; ++i) {
        matrix[0][i] = i;           // То же заполнение, по другим краям
    }

    int above_cell, left_cell, diagonal_cell, cost;

    for (int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {       // Для каждой ячейки массива
            cost = ( (src[i - 1] == dst[j - 1]) ? 0 : 1 );  // Если след. эл. по диагонали совпадает, то стоимость 0, иначе 1
            above_cell = matrix[i - 1][j];
            left_cell = matrix[i][j - 1];
            diagonal_cell = matrix[i - 1][j - 1];   // Просто записываем, где выше ячейка, где ниже
            matrix[i][j] = min(min(above_cell + 1, left_cell + 1), diagonal_cell + cost);   // Иии... Записываем в (i,j) элемент матирцы минимум из трех переходов: с верхней со стоимостью 1, слева со стоимостью 1 или же с диагонали со стоимостью cost (он равен 1)
        }
    }

    return matrix[m][n];
}

int main() {
    string s1 = "";
    string s2 = "";
    getline(cin, s1);
    getline(cin, s2);
    int c = levenshtein_distance(s1, s2);  // Вся магия
    cout << c;
}