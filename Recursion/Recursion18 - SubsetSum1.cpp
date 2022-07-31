/*************************************************************************************

Recursion - 18:- Subset Sum I (Recursion on Subsequences)

Time Complexity:- O(2^n) + O(n log (n)) 
Space Complexity:- O(2^n)

**************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void subsetSumsHelper(int index, int sum, vector<int>& arr, vector<int>& out, int N)
{
    if(index == N)
    {
        out.push_back(sum);
        return;
    }
    
    subsetSumsHelper(index + 1, sum + arr[index], arr, out, N);
    subsetSumsHelper(index + 1, sum, arr, out, N);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> out;
    subsetSumsHelper(0, 0, arr, out, N);
    sort(out.begin(), out.end());
    return out;
}

int main()
{
    vector<int> candidates{5, 2, 1};
    vector<int> out = subsetSums(candidates, 3);

    for(auto &it: out)
        cout << it << " ";
    return 0;
}
