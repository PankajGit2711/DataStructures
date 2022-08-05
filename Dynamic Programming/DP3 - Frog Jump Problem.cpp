/*****************************************************************************************

Dynamic Programming - 3:- Frog Jump Problem

Time Complexity:-
1. Recursion:- O(2^n)
2. Memoization:- O(n); Repeated Recursion calls are constant
3. Tabulation:- O(n); Loop is running from 1 to n.
4. Space Optimization:- O(n); Loop is running from 1 to n.

Space Complexity:-
1. Recursion:- O(n)
2. Memoization:- O(2n); Recursion Stack Space + DP Array
3. Tabulation:- O(n); No Recursion Stack Space is used.
4. Space Optimization:- O(1); No Recursion Stack Space as well as DP Array is used.

*****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;


// 1. Recursion
int frogJumpRecursionHelper(int index, vector<int>& heights)
{
    if(index == 0)
        return 0;
    
    int jumpLeft = frogJumpRecursionHelper(index - 1, heights) + abs(heights[index] - heights[index - 1]);
    int jumpRight = INT_MAX;
    if(index > 1)
        jumpRight = frogJumpRecursionHelper(index - 2, heights) + abs(heights[index] - heights[index - 2]);
    
    return min(jumpLeft, jumpRight);
}

int frogJumpRecursion(int n, vector<int> &heights)
{
    return frogJumpRecursionHelper(n - 1, heights);
}

// 2. Memoization
int frogJumpMemoizationHelper(int index, vector<int>& heights, vector<int>& dp)
{
    if(index == 0)
        return 0;
    
    if(dp[index] != -1)
        return dp[index];
    
    int jumpLeft = frogJumpMemoizationHelper(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    int jumpRight = INT_MAX;
    if(index > 1)
        jumpRight = frogJumpMemoizationHelper(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
    
    return dp[index] = min(jumpLeft, jumpRight);
}

int frogJumpMemoization(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    return frogJumpMemoizationHelper(n - 1, heights, dp);
}

// 3. Tabulation
int frogJumpTabulation(int n, vector<int>& heights) 
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    
    for(int i = 1; i < n; i++)
    {
        int jumpLeft = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int jumpRight = INT_MAX;
        if(i > 1)
            jumpRight = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            
        dp[i] = min(jumpLeft, jumpRight);
    }
    return dp[n - 1];
}

// 4. Space Optimization
int frogJumpSO(int n, vector<int>& heights)
{
    int prev2 = 0;
    int prev1 = 0;
    
    for(int i = 1; i < n; i++)
    {
        int jumpLeft = prev1 + abs(heights[i] - heights[i - 1]);
        int jumpRight = INT_MAX;
        if(i > 1)
            jumpRight = prev2 + abs(heights[i] - heights[i - 2]);
        
        int curr = min(jumpLeft, jumpRight);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> heights{10, 20, 30, 10};
    int out1 = frogJumpRecursion(n, heights);
    int out2 = frogJumpMemoization(n, heights);
    int out3 = frogJumpTabulation(n, heights);
    int out4 = frogJumpSO(n, heights);
    
    cout << out1 << " " << out2 << " " << out3 << " " << out4 << endl;
    return 0;
}