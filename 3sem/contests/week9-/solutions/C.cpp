//
// Created by aleksei on 01.11.17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> nums;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if(find(nums.begin(), nums.end(), tmp) == nums.end())
            nums.push_back(tmp);
    }

    cout << nums.size() << endl;
}