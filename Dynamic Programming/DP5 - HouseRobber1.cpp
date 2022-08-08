/****************************************************************************************************

Dynamic Programming - 5:- House Robber 1 (Maximum Sum of Non Adjacent Elements)

Time Complexity:-
1. Recursion:- O(2^n); 2^n overlapping subproblems with each subproblems having 2 choices.
2. Memoization:- O(n); n subproblems with each subproblems having 2 choices (pick/notPick).
3. Tabulation:- O(n); Single loop will run from 1 to n.
4. Space Optimization:- O(n); Single loop will run from 1 to n.

Space Complexity:-
1. Recursion:- O(n); Recursion Stack Space.
2. Memoization:- O(2n); Recursion Stack Space + DP Array
3. Tabulation:- O(n); DP Array Space.
4. Space Optimization:- O(1); No DP Array and Recursion Stack Space

******************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
int houseRobberRecursionHelper(int index, vector<int>& arr)
{
    if(index == 0)
        return arr[index];
        
    if(index < 0)
        return 0;
        
    int pick = arr[index] + houseRobberRecursionHelper(index - 2, arr);
    int notPick = 0 + houseRobberRecursionHelper(index - 1, arr);
    
    return max(pick, notPick);
}

int houseRobberRecursion(vector<int>& arr, int n) 
{
    return houseRobberRecursionHelper(n - 1, arr);
}

// 2. Memoization
int houseRobberMemoizationHelper(int index, vector<int>& arr, vector<int>& dp)
{
    if(index == 0)
        return arr[index];
    
    if(index < 0)
        return 0;
    
    if(dp[index] != -1)
        return dp[index];
        
    int pick = arr[index] + houseRobberMemoizationHelper(index - 2, arr, dp);
    int notPick = 0 + houseRobberMemoizationHelper(index - 1, arr, dp);
    
    return dp[index] = max(pick, notPick);
}

int houseRobberMemoization(vector<int>& arr, int n) 
{
    vector<int> dp(n + 1, -1);
    return houseRobberMemoizationHelper(n - 1, arr, dp);
}

// 3. Tabulation
int houseRobberTabulation(vector<int>& arr, int n) 
{
    vector<int> dp(n, -1);
    dp[0] = arr[0];

    for(int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if(i > 1)
            pick += dp[i - 2];
            
        int notPick = 0 + dp[i - 1];
        
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}

// 4. Space Optimization
int houseRobberSO(vector<int>& arr, int n)
{
    int prev2 = 0;
    int prev1 = arr[0];
    
    for(int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if(i > 1)
            pick += prev2;
        
        int notPick = 0 + prev1;
        
        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// Driver Code
int main()
{
    vector<int> arr{1, 2, 3, 1};
    int n = arr.size();
    int out1 = houseRobberRecursion(arr, n);
    int out2 = houseRobberMemoization(arr, n);
    int out3 = houseRobberTabulation(arr, n);
    int out4 = houseRobberSO(arr, n);

    cout << out1 << " " << out2 << " " << out3  << " " << out4 << endl;
    return 0;
}