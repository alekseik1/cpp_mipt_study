//
// Created by aleksei on 03.10.17.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s = "";
    getline(cin, s);
    int n = s.size();

    int max = 0;
    for(int i = 0; i < n; i++) {    // Для каждого символа
        for(int j = 0; j <= i; j++) {      // Провеяем символ слева и символ справа на равенство
            if(s[i+j] != s[i-j]) {  // Если не равны, то палиндром закончился на этой позиции
                break;
            } else{         // Иначе - увеличиваем счетчик длины и мерим дальше
                max++;
            }
        }
        cout << 2*max-1 << " ";     // Выводим длину. (2*max - 1) потому, что мы так устроили счетчик: начали его с 0, а не 1, да и еще увеличиваем на 1 на итераци, а не на 2. Увы, я такой :)
        max = 0;
    }
    return 0;
}