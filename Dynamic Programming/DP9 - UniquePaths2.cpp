/***********************************************************************************************************************************

Dynamic Programming - 9:- Unique Paths 2 - Number of Unique Paths With Obstacles 

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
int uniquePaths2RecursionHelper(int row, int col, vector<vector<int>>& obstacleGrid)
{
    if(row >= 0 && col >= 0 && obstacleGrid[row][col] == 1)
        return 0;
        
    if(row == 0 && col == 0)
        return 1;
    
    if(row < 0 || col < 0)
        return 0;
    
    int upDirection = uniquePaths2RecursionHelper(row - 1, col, obstacleGrid);
    int leftDirection = uniquePaths2RecursionHelper(row, col - 1, obstacleGrid);
    
    return upDirection + leftDirection;
}

int uniquePaths2Recursion(vector<vector<int>>& obstacleGrid) 
{
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    return uniquePaths2RecursionHelper(row - 1, col - 1, obstacleGrid);
}

// 2. Memoization
int uniquePaths2MemoizationHelper(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
{
    if(row >= 0 && col >= 0 && obstacleGrid[row][col] == 1)
        return 0;
    
    if(row == 0 && col == 0)
        return 1;
    
    if(row < 0 || col < 0)
        return 0;
    
    if(dp[row][col] != -1)
        return dp[row][col];
    
    int upDirection = uniquePaths2MemoizationHelper(row - 1, col, obstacleGrid, dp);
    int leftDirection = uniquePaths2MemoizationHelper(row, col - 1, obstacleGrid, dp);
    
    return dp[row][col] = upDirection + leftDirection;
}

int uniquePaths2Memoization(vector<vector<int>>& obstacleGrid) 
{
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));
    return uniquePaths2MemoizationHelper(row - 1, col - 1, obstacleGrid, dp);
}

// 3. Tabulation
int uniquePaths2Tabulation(vector<vector<int>>& obstacleGrid)
{
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, -1));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
                continue;
            }
            else if(i == 0 && j == 0){
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
int uniquePaths2SO(vector<vector<int>>& obstacleGrid)
{
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<int> prev(col, -1);
    
    for(int i = 0; i < row; i++)
    {
        vector<int> curr(col, -1);
        for(int j = 0; j < col; j++)
        {
            if(obstacleGrid[i][j] == 1)
            {
                curr[j] = 0;
                continue;
            }
            
            else if(i == 0 && j == 0)
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
    vector<vector<int>> obstacleGrid{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    
    int out1 = uniquePaths2Recursion(obstacleGrid);
    int out2 = uniquePaths2Memoization(obstacleGrid);
    int out3 = uniquePaths2Tabulation(obstacleGrid);
    int out4 = uniquePaths2SO(obstacleGrid);
    cout << out1 << " " << out2 << " " << out3 << " " << out4 << endl;
    return 0;
}