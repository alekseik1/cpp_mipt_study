//
// Created by aleksei on 26.09.17.
//

#include<iostream>
#include <cstdlib>

using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    double** buffer = (double**) malloc(M*N*sizeof(double));
    if(buffer == NULL) {
        // Не удалось создать, уходим
        return -1;
    }
    for(int i = 0; i < M; i++) {
        *(buffer + i*sizeof(double*)) = (double*) malloc(N*sizeof(double));
    }

    double** buffer1 = (double**) calloc(N*K, sizeof(double));
    if(buffer1 == NULL) {
        // Не удалось создать, уходим
        return -1;
    }
    for(int i = 0; i < N; i++) {
        *(buffer + i*sizeof(double*)) = (double*) calloc(K, sizeof(double));
    }

    double* buffer2 = new double[M];

    // Initialize first matrix
    for(int i=0; i < M; i++) {
        for(int j=0; j < N; j++) {
            // ОЧЕНЬ СЛОЖНО
            // берем buffer, сдвигаем его на i позиций (по памяти это будет сдвиг на i размеров указателя
            // второго порядка **), затем разыменовываем его, получаем указатель первого порядка. Его мы сдвигаем на
            // j позиций (опять же, прибавление j размеров указателя первого порядка) и полученное место памяти
            // разыменовываем - получаем наше значение массива. Я ненавижу C++
            *(*(buffer + i*sizeof(double**)) + j*sizeof(double*)) = i + j;
        }
    }
    // cout first matrix
    for(int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout <<*(*(buffer + i*sizeof(double**)) + j*sizeof(double*))  << " ";
        }
        cout << "\n";
    }

    // Initialize second matrix

    return 0;
}