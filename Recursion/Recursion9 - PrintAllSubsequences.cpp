/******************************************************************************

Recursion - 9:- Subsets (Print All Subsequences) - Leetcode (Recursion on Subsequences)

Time Complexity = O(2^n) * O(n)            Space Complexity:- O(n) 

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void printAllSubsequences(vector<int>& arr, vector<int>& temp, int index)
{
    int size = arr.size();
    if(index >= size)
    {
        for(auto &it: temp)
            cout << it << " ";
            
        if(temp.size() == 0)
            cout << "{}" << endl;
        
        cout << endl;
        return;
    }
    
    temp.push_back(arr[index]);
    printAllSubsequences(arr, temp, index + 1);
    temp.pop_back();
    printAllSubsequences(arr, temp, index + 1);
}


int main()
{
    vector<int> arr{3, 1, 2};
    vector<int> temp;
    printAllSubsequences(arr, temp, 0);
    return 0;
}