/*************************************************************************************

Recursion - 14:- Combination Sum - Leetcode (Recursion on Subsequences)

Time Complexity:- O(2^target) * O(n)     Space Complexity:- O(length * combinations)

**************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void combinationSumHelper(int index, vector<vector<int>>& out, vector<int>& temp, vector<int>& candidates, int target)
{
    int size = candidates.size();
    if(index == size)
    {
        if(target == 0)
            out.push_back(temp);
        return;
    }
    
    if(candidates[index] <= target)
    {
        temp.push_back(candidates[index]);
        combinationSumHelper(index, out, temp, candidates, target - candidates[index]);
        temp.pop_back();
    }
    
    combinationSumHelper(index + 1, out, temp, candidates, target);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> out;
    vector<int> temp;
    combinationSumHelper(0, out, temp, candidates, target);
    return out;
}

int main()
{
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    
    vector<vector<int>> out = combinationSum(candidates, target);

    for(auto &i: out)
    {
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
