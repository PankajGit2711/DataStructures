/******************************************************************************

Recursion - 13:- Count Number of Subsequences Having Sum K (Recursion on Subsequences)

Time Complexity = O(2^n)           Space Complexity:- O(n) 

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int countNumberOfSubsequencesSumK(vector<int>& arr, int index, int sum, int target)
{
    int size = arr.size();
    if(index == size)
    {
        if(sum == target)
            return 1;
        else
            return 0;
    }
    
    sum += arr[index];
    int left = countNumberOfSubsequencesSumK(arr, index + 1, sum, target);
        
    sum -= arr[index];
    int right = countNumberOfSubsequencesSumK(arr, index + 1, sum, target);
        
    return left + right;
}

int main()
{
    vector<int> arr{1, 2, 1, 2, 1};
    int target = 3;
    cout << countNumberOfSubsequencesSumK(arr, 0, 0, target) << endl;
    return 0;
}