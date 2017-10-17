#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    int N;
    std::cin >> N;
    int src, dest;
    std::cin >> src >> dest;
    // Костыльно уменьшаем на один
    src--;
    dest--;
    int** Mass = new int*[N];
    for (int i = 0; i < N; i++) {
        Mass[i] = new int[N];
    }

    // Ввод
    for (int length = 0; length < N; length++) {
        for (int width = 0; width < N; width++) {
            std::cin >> Mass[length][width];
        }
    }

    // Флойд-Уоршелл
    for (int k = 0; k < N; k++) {
        for (int length = 0; length < N; length++) {
            for (int width = 0; width < N; width++) {
                if (Mass[length][k] == -1 || Mass[k][width] == - 1) {   // Если пути нет
                    continue;
                }
                else {
                    if(Mass[length][width] == -1) {
                        Mass[length][width] = Mass[length][k] + Mass[k][width];
                    }
                    else {
                        Mass[length][width] = min(Mass[length][width], Mass[length][k] + Mass[k][width]);
                    }
                }

            }
        }
    }

    std::cout << Mass[src][dest];

    for (int count = 0; count < N; count++) {
        delete[] Mass[count];
    }
    delete[] Mass;
    return 0;
}