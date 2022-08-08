/****************************************************************************************************

Dynamic Programming - 6:- House Robber 2 (Last element is adjacent of First)

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

// Space Optimization
int houseRobber2SO(vector<int>& arr, int n)
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
    vector<int> arr{2, 3, 2};
    int n = arr.size();
    
    vector<int> out1(arr.begin() + 1, arr.end());
    vector<int> out2(arr.begin(), arr.end() - 1);
    
    int out = max(houseRobber2SO(out1, n), houseRobber2SO(out2, n));
    cout << out << endl;
    return 0;
}