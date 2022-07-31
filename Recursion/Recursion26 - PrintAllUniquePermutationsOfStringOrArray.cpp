/***************************************************************************************

Recursion - 26:- Print all Unique Permutations of String / Array

Time Complexity:- O(n!) * O(n); n! for all permutations and n for looping over the array.
Space Complexity:- O(n) + O(n); n for HashMap and n for Auxiliary Space.

*****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void printAllUniquePermutationsHelper(int index, vector<int>& nums, vector<vector<int>>& out)
{
    int size = nums.size();
    if(index == size)
    {
        out.push_back(nums);
        return;
    }
    
    unordered_map<int, int> HashMap;
    
    for(int i = index; i < size; i++)
    {
        if(HashMap.find(nums[i]) != HashMap.end())
            continue;
        
        HashMap[nums[i]] += 1;
        
        swap(nums[index], nums[i]);
        printAllUniquePermutationsHelper(index + 1, nums, out);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> printAllUniquePermutations(vector<int>& nums) 
{
    vector<vector<int>> out;
    printAllUniquePermutationsHelper(0, nums, out);
    return out;
}

int main()
{
    vector<int> nums{1, 1, 3};
    
    vector<vector<int>> out = printAllUniquePermutations(nums);
    
    for(auto &i: out)
    {
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}