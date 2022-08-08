/***********************************************************************************************************************************

Dynamic Programming - 8:- Unique Paths 1 - Number of Unique Path Without Obstacles

Time Complexity:-
1. Recursion:- O(2^n * m); 2^n*m overlapping subproblem with each subproblem having m choices.
2. Memoization:- O(n * m); n subproblem with each subproblem having m choices.
3. Tabulation:- O(n * m); Nested loops where Outer loop is running n times and inner loop is running m times.
4. Space Optimization:- O(n * m); Nested loops where Outer loop is running n times and inner loop is running m times.

Space Complexity:-
1. Recursion:- O(n); Recursion Stack Space.
2. Memoization:- O(n) + O(n * m); Recursion Stack Space + DP Array.
3. Tabulation:- O(n * m); 2D DP Array.
4. Space Optimization:- O(n); 1D DP Array.

************************************************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
int uniquePathsRecursionHelper(int row, int col)
{
    if(row == 0 && col == 0)
        return 1;
        
    if(row < 0 || col < 0)
        return 0;
        
    int leftDirection = uniquePathsRecursionHelper(row, col - 1);
    int upDirection = uniquePathsRecursionHelper(row - 1, col);
    
    return leftDirection + upDirection;
}

int uniquePathsRecursion(int row, int col)
{
    return uniquePathsRecursionHelper(row - 1, col - 1);
}

// 2. Memoization
int uniquePathsMemoizationHelper(int row, int col, vector<vector<int>>& dp)
{
    if(row == 0 && col == 0)
        return 1;
        
    if(row < 0 || col < 0)
        return 0;
        
    if(dp[row][col] != -1)
        return dp[row][col];
        
    int leftDirection = uniquePathsMemoizationHelper(row, col - 1, dp);
    int upDirection = uniquePathsMemoizationHelper(row - 1, col, dp);
    
    return dp[row][col] = leftDirection + upDirection;
}

int uniquePathsMemoization(int row, int col)
{
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));
    return uniquePathsMemoizationHelper(row - 1, col - 1, dp);
}

// 3. Tabulation
int uniquePathsTabulation(int row, int col)
{
    vector<vector<int>> dp(row, vector<int>(col, -1));
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }
            
            int leftDirection = 0, upDirection = 0;
            if(i > 0)
                upDirection = dp[i - 1][j];
            if(j > 0)
                leftDirection = dp[i][j - 1];
                
            dp[i][j] = leftDirection + upDirection;
        }
    }
    return dp[row - 1][col - 1];
}

// 4. Space Optimization
int uniquePathsSO(int row, int col)
{
    vector<int> prev(col, -1);
    
    for(int i = 0; i < row; i++)
    {
        vector<int> curr(col, -1);
        for(int j = 0; j < col; j++)
        {
            if(i == 0 && j == 0)
            {
                curr[j] = 1;
                continue;
            }
            
            int upDirection = 0, leftDirection = 0;
            if(i > 0)
                upDirection = prev[j];
            if(j > 0)
                leftDirection = curr[j - 1];
            curr[j] = upDirection + leftDirection;
        }
        prev = curr;
    }
    return prev[col - 1];
}


// Driver Code
int main()
{
    int m, n;
    cin >> m >> n;
    
    int out1 = uniquePathsRecursion(m, n);
    int out2 = uniquePathsMemoization(m, n);
    int out3 = uniquePathsTabulation(m, n);
    int out4 = uniquePathsSO(m, n);
    cout << out1 << " " << out2 << " " << out3 << " " << out4 << endl;
    return 0;
}