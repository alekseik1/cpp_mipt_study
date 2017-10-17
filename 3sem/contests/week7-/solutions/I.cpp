#include <iostream>
#include <set>


int main()
{
    int N, M, src, dest;
    int a, b;
    std::set<int> Visited, firedVertex, currCheck;
    std::cin >> N >> M >> src >> dest;

    int** Mass = new int*[N];
    for (int i = 0; i < N; i++) {
        Mass[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                Mass[i][j] = 0;
            }
            else {
                Mass[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        // Здесь могли быть ваши веса
        Mass[a][b] = 1;
        Mass[b][a] = 1;
    }

    int time = 0;
    currCheck.insert(src);
    while (Visited.count(dest) != 1) {
        time++;
        while (currCheck.size() != 0) {
            int currVertex = *(currCheck.begin());
            for (int i = 0; i < N; i++)     // Конкурс: разожги всех соседей, если до них есть путь
                if (Mass[currVertex][i] == 1)
                    firedVertex.insert(i);
            Visited.insert(currVertex);
            currCheck.erase(currVertex);
        }
        currCheck = firedVertex;    // Только что зажженные в следующей итерации будут разжигать других. Старики при этом ушли на покой
        firedVertex.clear();    // Обнуляем перед следующим использованием firedVertex (по сути, он нужен только для подсчета внутри цикла
    }
    std::cout << time - 1;

    for (int i = 0; i < N; i++) {
        delete[] Mass[i];
    }
    delete[] Mass;

    return 0;
}