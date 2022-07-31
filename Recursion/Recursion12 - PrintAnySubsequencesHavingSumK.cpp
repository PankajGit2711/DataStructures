/******************************************************************************

Recursion - 12:- Print Any Subsequences Having Sum K (Recursion on Subsequences)

Time Complexity = O(2^n)           Space Complexity:- O(n) 

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool printAnySubsequencesSumK(vector<int>& arr, vector<int>& temp, int index, int sum, int target)
{
    int size = arr.size();
    if(index >= size)
    {
        if(sum == target)
        {
            for(auto &it: temp)
                cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    
    temp.push_back(arr[index]);
    sum += arr[index];
    
    if(printAnySubsequencesSumK(arr, temp, index + 1, sum, target))
        return true;
        
    temp.pop_back();
    sum -= arr[index];
    
    if(printAnySubsequencesSumK(arr, temp, index + 1, sum, target))
        return true;
        
    return false;
}


int main()
{
    vector<int> arr{1, 2, 1};
    vector<int> temp;
    int target = 3;
    printAnySubsequencesSumK(arr, temp, 0, 0, target);
    return 0;
}