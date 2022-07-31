/*************************************************************************************

Recursion - 19:- Subset Sum II (Recursion on Subsequences)

Time Complexity:- O(2^n) + O(n) + O(n log n)
Space Complexity:- O(2^n)

**************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void subsetsWithDupHelper(int index, vector<int>& nums, vector<vector<int>>& out, vector<int>& temp)
{
    int size = nums.size();
    out.push_back(temp);

    for(int i = index; i < size; i++)
    {
        if(i > index && nums[i] == nums[i - 1])
            continue;
        
        temp.push_back(nums[i]);
        subsetsWithDupHelper(i + 1, nums, out, temp);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> out;
    vector<int> temp;
    
    sort(nums.begin(), nums.end());
    
    subsetsWithDupHelper(0, nums, out, temp);
    return out;
}

int main()
{
    vector<int> candidates{1, 1, 2, 2, 2};
    vector<vector<int>> out = subsetsWithDup(candidates);

    for(auto &i: out)
    {
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
