//
// Created by aleksei on 01.11.17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

template<typename T>
bool contains(std::vector<T> v, T value)
{
    return std::find(v.begin(), v.end(), value) != v.end();
}

void dfs(std::vector<std::vector<int>> &g, const int start, std::vector<bool> &used){
    //std::cout << start << " "; // Действие над вершиной
    used[start] = true;
    for (int x : g[start])
        if (!used[x])
            dfs(g, x, used);
}

bool isConnected(std::map<int, std::vector<int>> matrix_, const int size, const int start = 0) {
    std::vector<bool> used;
    for(int i = 0; i < size; i++)
        used.push_back(false);
    std::vector<std::vector<int>> matr;
    for(int i = 0; i < size; i++) {
        matr.push_back(matrix_[i]);
    }
    dfs(matr, start, used);
    return std::count(used.begin(), used.end(), true) == size;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::map<int, std::vector<int>> matrix;
    bool hasOutput = false;
    for(int i = 1; i <= m; i++) {
        int from, to;
        std::cin >> from >> to;
        matrix[from].push_back(to);
        matrix[to].push_back(from);
        if(!hasOutput && isConnected(matrix, n)) {
            std::cout << i << "\n";
            hasOutput = true;
        }
    }
    return 0;
}