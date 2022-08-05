/*****************************************************************************************

Dynamic Programming - 2:- Climbing Stairs - Distinct Ways to reach Nth Chair

Time Complexity:-
1. Recursion:- O(2^n)
2. Memoization:- O(n); Repeated Recursion calls are constant
3. Tabulation:- O(n); Loop is running from 2 to n.
4. Space Optimization:- O(n); Loop is running from 2 to n.

Space Complexity:-
1. Recursion:- O(n)
2. Memoization:- O(2n); Recursion Stack Space + DP Array
3. Tabulation:- O(n); No Recursion Stack Space is used.
4. Space Optimization:- O(1); No Recursion Stack Space as well as DP Array is used.

*****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;


// 1. Recursion
int climbStairsRecursion(int n) 
{
    if(n == 0)
        return 1;
    
    if(n == 1)
        return 1;
    
    return climbStairsRecursion(n - 1) + climbStairsRecursion(n - 2);
}

// 2. Memoization
int climbStairsMemoizationHelper(int n, vector<int>& dp)
{
    if(n == 0)
        return 1;
    
    if(n == 1)
        return 1;
    
    if(dp[n] != -1)
        return dp[n];
    
    return dp[n] = climbStairsMemoizationHelper(n - 1, dp) + climbStairsMemoizationHelper(n - 2, dp);
}

int climbStairsMemoization(int n) 
{
    vector<int> dp(n + 1, -1);
    return climbStairsMemoizationHelper(n, dp);
}

// 3. Tabulation
int climbStairsTabulation(int n) 
{
    vector<int> dp(n + 1, -1);
    
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

// 4. Space Optimization
int climbStairsSO(int n)
{
    int prev2 = 1;
    int prev1 = 1;
    
    for(int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;
    int out1 = climbStairsRecursion(n);
    int out2 = climbStairsMemoization(n);
    int out3 = climbStairsTabulation(n);
    int out4 = climbStairsSO(n);
    
    cout << out1 << " " << out2 << " " << out3 << " " << out4 << endl;
    return 0;
}