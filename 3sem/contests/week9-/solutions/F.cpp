//
// Created by aleksei on 01.11.17.
//

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
bool contains(std::vector<T> v, T value)
{
    return std::find(v.begin(), v.end(), value) != v.end();
}

bool isConnected(const bool* a, int n) { // Чтобы получить a[i][j], надо брать a[i*n+j]. Ужас!
    // Let's select j
    int start = -1;
    for(int j = 0; j < n; j++) {
        if(a[0*n+j]) {
            start = j;
            break;
        }
    }
    if(start == -1) // Если уже первая оказалась ни с кем не связанной, то точно стоит вернуть false
        return false;
    // Стартуем bfs, потом посмотрим, всех ли захватили
    std::vector<int> fired, firing;
    firing.push_back(0);    // Зажигаем 0
    while(!firing.empty())  // Пока кто-то горит
    {
        int curr = firing.at(firing.size() - 1);
        firing.pop_back(); // Берем верхнего горящего
        for(int i = 0; i < n; i++)
        {
            if(a[curr*n + i] && !contains(fired, i))   // Если curr соседствует с i И i еще не ушел на пенсию
            {
                firing.push_back(i); // Зажигаем его
            }
        }
        fired.push_back(curr);  // curr всех зажег, теперь может отправляться на пенсию
    }
    // Вот мы и прошлись. Пора проверить, всех ли зацепили
    return fired.size() == n;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    bool* a = (bool*) malloc(n*n*sizeof(bool)); // Двумерная матрица смежности
    int res = 0;
    for(int i = 1; i <= m; i++)
    {
        int from, to;
        std::cin >> from >> to;
        a[n*from+to] = true;    // a[from][to]
        a[n*to + from] = true;  // a[to][from]
        if(isConnected(a, n)) {
            res = i;
            break;
        }
    }

    std::cout << res << "\n";
    free(a);
    return 0;
}