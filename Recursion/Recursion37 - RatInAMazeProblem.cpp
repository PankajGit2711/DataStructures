/*********************************************************************************************

Recursion - 37:- Rat In a Maze Problem

Time Complexity:- O(4^n*m); Because for every cell we are trying 4 different ways(D, L, R, U)
Space Complexity:- O(n * m); Auxiliary Recursion Space.

*********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void ratInAMazeHelper(int i, int j, vector<vector<int>>& mat, int n, vector<string>& out, string temp, vector<vector<int>>& visited)
{
    if(i == n - 1 && j == n - 1)
    {
        out.push_back(temp);
        return;
    }
    
    // Downward Direction
    if(i + 1 < n && visited[i + 1][j] == 0 && mat[i + 1][j] == 1)
    {
        visited[i][j] = 1;
        ratInAMazeHelper(i + 1, j, mat, n, out, temp + 'D', visited);
        visited[i][j] = 0;
    }
    
    // Leftward Direction
    if(j - 1 >= 0 && visited[i][j - 1] == 0 && mat[i][j - 1] == 1)
    {
        visited[i][j] = 1;
        ratInAMazeHelper(i, j - 1, mat, n, out, temp + 'L', visited);
        visited[i][j] = 0;
    }
    
     // Rightward Direction
    if(j + 1 < n && visited[i][j + 1] == 0 && mat[i][j + 1] == 1)
    {
        visited[i][j] = 1;
        ratInAMazeHelper(i, j + 1, mat, n, out, temp + 'R', visited);
        visited[i][j] = 0;
    }
    
     // Upward Direction
    if(i - 1 >= 0 && visited[i - 1][j] == 0 && mat[i - 1][j] == 1)
    {
        visited[i][j] = 1;
        ratInAMazeHelper(i - 1, j, mat, n, out, temp + 'U', visited);
        visited[i][j] = 0;
    }
}


vector<string> ratInAMaze(vector<vector<int>> &mat, int n) {
    vector<string> out;
    string temp = "";
    vector<vector<int>> visited(n, vector<int>(n, 0));
    
    if(mat[0][0] == 1)
        ratInAMazeHelper(0, 0, mat, n, out, temp, visited);
    return out;
}


int main()
{
    vector<vector<int>> mat
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = 4;
    
    vector<string> out = ratInAMaze(mat, n);
    
    for(auto &it: out)
        cout << it << endl;
    return 0;
}