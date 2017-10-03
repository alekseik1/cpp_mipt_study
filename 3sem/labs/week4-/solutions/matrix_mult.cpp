//
// Created by aleksei on 26.09.17.
//

#include<iostream>
#include <cstdlib>

using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    double* buffer = (double*) malloc(M*N*sizeof(double));
    if(buffer == NULL) {
        // Не удалось создать, уходим
        return -1;
    }
    // Первый инициализируем
    for(int i = 0; i < M; i++) {
        for(int j=0; j < N; j++) {
            *(buffer + (i*N+j)*sizeof(double)) = (double) (i+j);
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j=0; j < N; j++) {
            cout << *(buffer + (i*N+j)*sizeof(double)) << " ";
        }
        cout << endl;
    }

    int* buffer1 = (int*) calloc(K*N, sizeof(int));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            *(buffer1 + (i*K+j)*sizeof(int)) = ((i == j) ? 1 : 0);
        }
    }
    cout << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            cout << *(buffer1 + (i*K+j)*sizeof(int)) << " ";
        }
        cout << endl;
    }

    // Third
    double* buffer2 = new double[M*K];

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < K; j++) {
            double sum = 0;
            for(int i1 = 0; i1 < N; i1++) {
                sum += *(buffer + (i*N + i1)*sizeof(int))*(*(buffer1 + (i1*N + j)*sizeof(int)));
            }
            *(buffer2 + (i*K + j)*sizeof(double)) = sum;
        }
    }

    cout << endl;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < K; j++) {
            cout << *(buffer2 + (i*K + j)*sizeof(double)) << " ";
        }
        cout << endl;
    }


    free(buffer);
    free(buffer1);
    free(buffer2);
    return 0;
}