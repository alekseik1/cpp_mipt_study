//
// Created by aleksei on 01.11.17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// vector и string - часть std. Не забывайте об этом

void tolower(string& s)
{
    for(auto& c : s)
        c = (char) (tolower(c));
}

int main()
{
    int N; cin >> N;
    vector<string> all_words;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        tolower(tmp);
        if(find(all_words.begin(), all_words.end(), tmp) == all_words.end())
            all_words.push_back(tmp);
    }

    sort(all_words.begin(), all_words.end());

    while(!all_words.empty())
    {
        cout << all_words.at(all_words.size() - 1) << " ";
        all_words.pop_back();
    }

}