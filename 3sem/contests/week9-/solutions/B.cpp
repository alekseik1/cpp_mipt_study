//
// Created by aleksei on 01.11.17.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums;
    do
    {
        int tmp_input;
        cin >> tmp_input;
        if(tmp_input == 0)
            break;
        if(tmp_input > 0)
            nums.push_back(tmp_input);
        else {
            if (nums.size() == 0)
                continue;
            if (-tmp_input < nums.at(nums.size() - 1))
                nums.at(nums.size() - 1) += tmp_input;
            else if (nums.size() != 0)
                nums.pop_back();
        }
    } while(true);

    if(nums.size() != 0)
        cout << nums.size() << " " << nums.at(nums.size() - 1) << endl;
    else
        cout << 0 << " " << -1 << endl;
}