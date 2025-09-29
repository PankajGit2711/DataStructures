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
// This approach uses recursion with memoization (top-down dynamic programming).
// It stores the results of subproblems in a DP array to avoid redundant calculations.
int fibonacciNumberMemoization(int n, vector<int>& dp)
{
    // Base case: If n is 0 or 1, return n directly.
    if(n <= 1)
        return n;
        
    // If the result for this value of n is already computed, return it.
    if(dp[n] != -1)
        return dp[n];
        
    // Otherwise, compute the result recursively and store it in the DP array.
    return dp[n] = fibonacciNumberMemoization(n - 1, dp) + fibonacciNumberMemoization(n - 2, dp);
}

// 2. Tabulation
// This approach uses an iterative bottom-up dynamic programming technique.
// It fills the DP array iteratively from the base cases to the desired value.
int fibonacciNumberTabulation(int n, vector<int>& dp)
{
    // Base cases: Initialize the first two Fibonacci numbers.
    dp[0] = 0;
    dp[1] = 1;
        
    // Fill the DP array iteratively for all values from 2 to n.
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
        
    // Return the nth Fibonacci number.
    return dp[n];
}

// 3. Space Optimization
// This approach optimizes space by using only two variables instead of a DP array.
// It computes the Fibonacci numbers iteratively while maintaining only the last two values.
int fibonacciNumberSO(int n)
{
    // Base cases: Initialize the first two Fibonacci numbers.
    int prev2 = 0; // Represents F(n-2)
    int prev1 = 1; // Represents F(n-1)

    // Compute Fibonacci numbers iteratively for all values from 2 to n.
    for(int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2; // Current Fibonacci number
        prev2 = prev1;           // Update F(n-2) to the previous F(n-1)
        prev1 = curr;            // Update F(n-1) to the current Fibonacci number
    }
    // Return the nth Fibonacci number.
    return prev1;
}

int main()
{
    int n;
    cin >> n; // Input the value of n (the position of the Fibonacci number to compute)
    
    // Create DP arrays for memoization and tabulation approaches.
    vector<int> dp1(n + 1, -1); // Initialize with -1 for memoization
    vector<int> dp2(n + 1, -1); // Initialize for tabulation
    
    // Compute the nth Fibonacci number using all three approaches.
    int out1 = fibonacciNumberMemoization(n, dp1); // Memoization
    int out2 = fibonacciNumberTabulation(n, dp2); // Tabulation
    int out3 = fibonacciNumberSO(n);             // Space Optimization
    
    // Print the results of all three approaches.
    cout << out1 << " " << out2 << " " << out3 << endl;
    return 0;
}