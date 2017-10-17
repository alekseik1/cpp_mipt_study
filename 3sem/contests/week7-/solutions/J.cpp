//
// Created by aleksei on 17.10.17.
//

#include <iostream>
#include <algorithm>
#include <fstream>

#define INF 1000000

using namespace std;

void printMatrix(int** matrix, int numberOfVert) {
    for(int i = 0; i < numberOfVert; i++) {
        for(int j = 0; j < numberOfVert; j++) {
            if(matrix[i][j] == INF) {
                cout << "INF" << " ";
            }
            else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void FloydWarshall(int **matrix, int numberOfVert) {
    for(int k = 0; k < numberOfVert; k++) {
        for(int i = 0; i < numberOfVert; i++) {
            for(int j = 0; j < numberOfVert; j++) {
                if(matrix[i][j] == INF) continue;
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}

int main() {
    int numberOfVert, start, stop;
    cin >> numberOfVert >> start >> stop;

    // На пафосе аллоцируем память. Как бы segmentation fault не словить :|
    int **matrix = (int**) malloc(sizeof(int) * numberOfVert);
    for(int i = 0; i < numberOfVert; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * numberOfVert);
    }

    //Считываем матрицу весов ребер
    for(int i = 0; i < numberOfVert; i++) {
        for(int j = 0; j < numberOfVert; j++) {
            int tmp = 0;
            cin >> tmp;
            if(tmp != 0) {
                matrix[i][j] = tmp;
            }
            else {
                matrix[i][j] = INF;
            }
        }
    }

    FloydWarshall(matrix, numberOfVert);
    printMatrix(matrix, numberOfVert);
    int res = matrix[start-1][stop-1];
    cout << ((res >= INF) ? -1 : res);

    return 0;
}