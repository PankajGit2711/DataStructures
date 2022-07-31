/*************************************************************************************

Recursion - 17:- Combination Sum II - Leetcode (Recursion on Subsequences)

Time Complexity:- O(2^target) * O(length of combinations) 
Space Complexity:- O(length * combinations)

**************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void combinationSum2Helper(int index, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& out, int target)
{
    int size = candidates.size();
    if(target == 0)
    {
        out.push_back(temp);
        return;
    }
    
    for(int i = index; i < size; i++)
    {
        if(i > index && candidates[i] == candidates[i - 1])
            continue;
        if(candidates[i] > target)
            break;
        
        temp.push_back(candidates[i]);
        combinationSum2Helper(i + 1, candidates, temp, out, target - candidates[i]);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> out;
    vector<int> temp;
    
    combinationSum2Helper(0, candidates, temp, out, target);
    return out;
}

int main()
{
    vector<int> candidates{1, 1, 1, 2, 2};
    int target = 4;
    
    vector<vector<int>> out = combinationSum2(candidates, target);

    for(auto &i: out)
    {
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
