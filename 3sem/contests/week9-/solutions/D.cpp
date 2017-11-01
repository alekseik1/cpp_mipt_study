//
// Created by aleksei on 01.11.17.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void tolower(string& s)
{
    for(auto& c : s)
        c = (char) (tolower(c));
}

template<typename T>
bool contains(vector<T> v, T value)
{
    return find(v.begin(), v.end(), value) != v.end();
}

int main()
{
    int N; cin >> N;
    vector<string> all_words;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        tolower(tmp);
        all_words.push_back(tmp);
    }
    int prev = 0;
    string word = "";
    for(auto& word_ : all_words)
    {
        int curr = count(all_words.begin(), all_words.end(), word_);
        if(curr > prev) {
            prev = curr;
            word = word_;
        }
        //cout << word << " ";
    }

    cout << word << " " << prev << endl;
}