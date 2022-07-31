/***************************************************************************************

Recursion - 25:- Print all Permutations of String / Array

Time Complexity:- O(n!) * O(n); n! for all permutations and n for looping over the array.
Space Complexity:- O(n); where n is Auxiliary Space

*****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void printAllPermutationsHelper(int index, vector<int>& nums, vector<vector<int>>& out)
{
    int size = nums.size();
    if(index == size)
    {
        out.push_back(nums);
        return;
    }
            
    for(int i = index; i < size; i++)
    {
        swap(nums[index], nums[i]);
        printAllPermutationsHelper(index + 1, nums, out);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> printAllPermutations(vector<int>& nums) 
{
    vector<vector<int>> out;
    printAllPermutationsHelper(0, nums, out);
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