/***********************************************************************************************************************************

Dynamic Programming - 7:- Ninja's Training 

Time Complexity:-
1. Recursion:- O(2^N * 4 * 3); 2^N * 4 states and for every state, we are running a loop three times.
2. Memoization:- O(N * 4 * 3); N * 4 states and for every state, we are running a loop three times.
3. Tabulation:- O(N * 4 * 3); Three Nested Loops (Outer will run N times, inner will run 4 times and innermost will run 3 times).
4. Space Optimization:- O(N * 4 * 3); Three Nested Loops (Outer will run N times, inner will run 4 times and innermost will run 3 times).

Space Complexity:-
1. Recursion:- O(N); Recursion Stack Space.
2. Memoization:- O(N) + O(N * 4); Recursion Stack Space + DP Array of size N * 4.
3. Tabulation:- O(N * 4); DP Array of size N * 4.
4. Space Optimization:- O(4); DP Array of Size 4.

************************************************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
int ninjaTrainingRecursionHelper(int index, vector<vector<int>>& points, int lastTask)
{
    if(index == 0)
    {
        int maxPoints = 0;
        for(int task = 0; task < 3; task++)
        {
            if(task != lastTask)
                maxPoints = max(maxPoints, points[0][task]);
        }
        return maxPoints;
    }
    
    int maxPoints = 0;
    for(int task = 0; task < 3; task++)
    {
        if(task != lastTask)
        {
            int totalPoints = points[index][task] + ninjaTrainingRecursionHelper(index - 1, points, task); 
            maxPoints = max(maxPoints, totalPoints);
        }
    }
    return maxPoints;
}

int ninjaTrainingRecursion(int n, vector<vector<int>>& points)
{
    return ninjaTrainingRecursionHelper(n - 1, points, 3);
}

// 2. Memoization
int ninjaTrainingMemoizationHelper(int index, vector<vector<int>>& points, int lastTask, vector<vector<int>>& dp)
{
    if(index == 0)
    {
        int maxPoints = 0;
        for(int task = 0; task < 3; task++)
        {
            if(task != lastTask)
                maxPoints = max(maxPoints, points[0][task]);
        }
        return maxPoints;
    }
    
    if(dp[index][lastTask] != -1)
        return dp[index][lastTask];
    
    int maxPoints = 0;
    for(int task = 0; task < 3; task++)
    {
        if(task != lastTask)
        {
            int totalPoints = points[index][task] + ninjaTrainingMemoizationHelper(index - 1, points, task, dp); 
            maxPoints = max(maxPoints, totalPoints);
        }
    }
    return dp[index][lastTask] = maxPoints;
}

int ninjaTrainingMemoization(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return ninjaTrainingMemoizationHelper(n - 1, points, 3, dp);
}

// 3. Tabulation
int ninjaTrainingTabulation(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day = 1; day < n; day++)
    {
        for(int lastTask = 0; lastTask < 4; lastTask++)
        {
            dp[day][lastTask] = 0;            
            for(int task = 0; task < 3; task++)
            {
                if(task != lastTask)
                {
                    int totalPoints = points[day][task] + dp[day - 1][task];
                    dp[day][lastTask] = max(dp[day][lastTask], totalPoints);
                }
            }
        }
    }
    return dp[n - 1][3];
}

// 4. Space Optimization
int ninjaTrainingSO(int n, vector<vector<int>> &points)
{
    vector<int> dp(4, -1);
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day = 1; day < n; day++)
    {
        vector<int> temp(4, -1);
        for(int lastTask = 0; lastTask < 4; lastTask++)
        {
            temp[lastTask] = 0;            
            for(int task = 0; task < 3; task++)
            {
                if(task != lastTask)
                    temp[lastTask] = max(temp[lastTask], points[day][task] + dp[task]);
            }
        }
        dp = temp;
    }
    return dp[3];
}


// Driver Code
int main()
{
    vector<vector<int>> points{
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    int day = points.size();
    
    int out1 = ninjaTrainingRecursion(day, points);
    int out2 = ninjaTrainingMemoization(day, points);
    int out3 = ninjaTrainingTabulation(day, points);
    int out4 = ninjaTrainingSO(day, points);
    cout << out1 << " " << out2 << " " << out3 << " " << out4 << endl;
    return 0;
}