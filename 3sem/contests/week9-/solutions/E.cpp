//
// Created by aleksei on 01.11.17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

template<typename T>
bool contains(vector<T> v, T value)
{
    return find(v.begin(), v.end(), value) != v.end();
}

int main()
{
    int N; cin >> N;
    map<int, vector<int>> table;
    for(int i = 0; i < N; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        vector<int> tmp;
        tmp.push_back(1);
        tmp.push_back(weight);
        auto ret = table.insert(pair<int, vector<int>>(from, tmp));
        if(!ret.second) // Already exists
        {
            auto& tmp_vector = ret.first->second;
            tmp_vector.at(0)++; // Number of paths
            tmp_vector.at(1) += weight; // Total weight
        }
    }

    for(auto& c : table){
        cout << c.first << " " << c.second.at(0) << " " << c.second.at(1) << endl;
    }
}