/************************************************************************************************

Recursion - 24:- Print all Permutations of String / Array - Leetcode

Time Complexity:- O(n!) * O(n); n! Permutations and looping for every permutation from 0 to n. 
Space Complexity:- O(n) + O(n); temperory data structure to store permutations and visited array. 

**************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void printAllPermutationsHelper(vector<int>& nums, vector<vector<int>>& out, vector<int>& temp, vector<int>& visited, int size)
{
    if(temp.size() == size)
    {
        out.push_back(temp);
        return;
    }
    
    for(int i = 0; i < size; i++)
    {
        if(visited[i] == 0)
        {
            temp.push_back(nums[i]);
            visited[i] = 1;
            printAllPermutationsHelper(nums, out, temp, visited, size);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}

vector<vector<int>> printAllPermutations(vector<int>& nums) 
{
    int size = nums.size();
    vector<vector<int>> out;
    vector<int> temp;
    vector<int> visited(size, 0);
    printAllPermutationsHelper(nums, out, temp, visited, size);
    return out;
}

int main()
{
    vector<int> nums{1, 2, 3};
    vector<vector<int>> out = printAllPermutations(nums);
    
    for(auto &i: out)
    {
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}