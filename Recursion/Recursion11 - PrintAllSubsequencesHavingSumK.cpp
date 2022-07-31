/******************************************************************************

Recursion - 11:- Print All Subsequences Having Sum K (Recursion on Subsequences)

Time Complexity = O(2^n) * O(n)            Space Complexity:- O(n) 

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void printAllSubsequencesSumK(vector<int>& arr, vector<int>& temp, int index, int sum, int target)
{
    int size = arr.size();
    if(index >= size)
    {
        if(sum == target)
        {
            for(auto &it: temp)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    
    temp.push_back(arr[index]);
    sum += arr[index];
    printAllSubsequencesSumK(arr, temp, index + 1, sum, target);
    temp.pop_back();
    sum -= arr[index];
    printAllSubsequencesSumK(arr, temp, index + 1, sum, target);
}


int main()
{
    vector<int> arr{3, 1, 2};
    vector<int> temp;
    int target = 3;
    printAllSubsequencesSumK(arr, temp, 0, 0, target);
    return 0;
}