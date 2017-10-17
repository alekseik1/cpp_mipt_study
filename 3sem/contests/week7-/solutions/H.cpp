#include <iostream>

using namespace std;

void dfs(int** Colour, int* Visited, int N, int start) {
    Visited[start] = 1;
    for (int i = 0; i < N; i++) {
        if (Colour[start][i] == 1) {
            if (Visited[i] == 0) {
                dfs(Colour, Visited, N, i);
            }
        }
    }
}

int main(){
    bool hasUnvisited = false;
    int numberOfVertex, numberOfPaths;
    cin >> numberOfVertex >> numberOfPaths;
    int a, b;
    int** Mass = new int*[numberOfVertex];
    int* Visit = new int[numberOfVertex];



    for (int i = 0; i < numberOfVertex; i++) {
        Mass[i] = new int[numberOfVertex];
        Visit[i] = 0;
    }

    for (int i = 0; i < numberOfVertex; i++) {
        for (int j = 0; j < numberOfVertex; j++) {
            Mass[i][j] = 0;
        }
    }

    // Ввод
    for (int i = 0; i < numberOfPaths; i++) {
        cin >> a >> b;
        Mass[a][b] = Mass[b][a] = 1;
    }

    dfs(Mass, Visit, numberOfVertex, 0);

    for (int i = 0; i < numberOfVertex; i++) {
        if (Visit[i] == 0) {
            std::cout << "NO";
            hasUnvisited = true;
            break;
        }
    }

    if (!hasUnvisited) {
        std::cout << "YES";
    }

    // Memory cleanup
    for (int i = 0; i < numberOfVertex; i++) {
        delete[] Mass[i];
    }
    delete[] Mass;
    delete[] Visit;
    return 0;
}
