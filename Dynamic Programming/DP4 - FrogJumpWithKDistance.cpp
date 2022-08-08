/****************************************************************************************************

Dynamic Programming - 4:- Frog Jump with K Distance

Time Complexity:-
1. Recursion:- O(2^n * k); 2^n overlapping subproblems with each subproblems having k choices.
2. Memoization:- O(n * k); n subproblems with each subproblems having k choices.
3. Tabulation:- O(n * k); Nested loops where outer loop will run n times and inner will run k times.

Space Complexity:-
1. Recursion:- O(n); Recursion Stack Space.
2. Memoization:- O(2n); Recursion Stack Space + DP Array
3. Tabulation:- O(n); DP Array Space.

******************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
int frogJumpKRecursionHelper(int index, vector<int>& heights, int k)
{
    if(index == 0)
        return 0;
        
    int minJumps = INT_MAX;
    for(int i = 1; i <= k; i++)
    {
        if(index - i >= 0)
        {
            int jumps = frogJumpKRecursionHelper(index - i, heights, k) + abs(heights[index] - heights[index - i]);
            minJumps = min(minJumps, jumps);
        }
    }
    return minJumps;
}

int frogJumpKRecursion(int n, vector<int>& heights, int k)
{
    return frogJumpKRecursionHelper(n - 1, heights, k);
}

// 2. Memoization
int frogJumpKMemoizationHelper(int index, int k, vector<int>& heights, vector<int>& dp)
{
    if(index == 0)
        return 0;
    
    if(dp[index] != -1)
        return dp[index];
    
    int minJumps = INT_MAX;
    for(int i = 1; i <= k ; i++)
    {
        if(index - i >= 0)
        {
            int jumps = frogJumpKMemoizationHelper(index - i, k, heights, dp) + abs(heights[index] - heights[index - i]);
            minJumps = min(minJumps, jumps);
        }
    }
    return dp[index] = minJumps;
}
 
int frogJumpKMemoization(int n, vector<int>& heights, int k)
{
    vector<int> dp(n + 1, -1);
    return frogJumpKMemoizationHelper(n - 1, k, heights, dp);
}

// 3. Tabulation
int frogJumpKTabulation(int n, vector<int>& heights, int k)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    
    for(int i = 1; i < n; i++)
    {
        int minJumps = INT_MAX;
        for(int j = 1; j <= k; j++)
        {
            if(i - j >= 0)
            {
                int jumps = dp[i - j] + abs(heights[i] - heights[i - j]);
                minJumps = min(minJumps, jumps);
            }
        }
        dp[i] = minJumps;
    }
    return dp[n - 1];
}

// Driver Code
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int out1 = frogJumpKRecursion(n, heights, k);
    int out2 = frogJumpKMemoization(n, heights, k);
    int out3 = frogJumpKTabulation(n, heights, k);

    cout << out1 << " " << out2 << " " << out3 << endl;
    return 0;
}