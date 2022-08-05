/*****************************************************************************************

Dynamic Programming - 1:- Print Nth Fibonacci Number

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

// 1. Memoization
int fibonacciNumberMemoization(int n, vector<int>& dp)
{
    if(n <= 1)
        return n;
        
    if(dp[n] != -1)
        return dp[n];
        
    return dp[n] = fibonacciNumberMemoization(n - 1, dp) + fibonacciNumberMemoization(n - 2, dp);
}

// 2. Tabulation
int fibonacciNumberTabulation(int n, vector<int>& dp)
{
    dp[0] = 0;
    dp[1] = 1;
        
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
        
    return dp[n];
}

// 3. Space Optimization
int fibonacciNumberSO(int n)
{
    int prev2 = 0;
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
    vector<int> dp1(n + 1, -1);
    vector<int> dp2(n + 1, -1);
    
    int out1 = fibonacciNumberMemoization(n, dp1);
    int out2 = fibonacciNumberTabulation(n, dp2);
    int out3 = fibonacciNumberSO(n);
    cout << out1 << " " << out2 << " " << out3 << endl;
    return 0;
}