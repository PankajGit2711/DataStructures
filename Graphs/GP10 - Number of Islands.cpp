/*
GP9 - Number of Islands in a Grid

Time Complexity = O(n^2) * 9 = O(n^2)// As we are traversing a matrix for which we use 2 loops and each node has 9 neighbours so O(n^2) * 9 will be the time complexity.
Space Complexity = O(n^2) + O(n^2) = O(n^2) // 2D Visited Array + Queue will hold at max O(n^2) elements. So overall space complexity is O(n^2).

Tested with the following input gives following output
Input: Number of Rows in Grid = 5, Number of Columns in Grid = 5, Grid = [[1, 1, 0, 0, 0], [0, 1, 0, 0, 1], [1, 0, 0, 1, 1], [0, 0, 0, 0, 0], [1, 0, 1, 1, 0]]
Output: 4
*/ 

#include <bits/stdc++.h>

using namespace std;

void traverseBFS(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited)
{
    visited[i][j] = true; // As soon as we come into this function mark the current node grid[i][j] as visited.
    
    // Create the Queue of pair<int, int> as part of initial config for BFS to add current i (row), j (col) position of the node.
    queue<pair<int, int>> q;
    q.push({i, j}); // Push the current i (row), j (col) in the queue.
    
    // While queue is not empty perform the following operations:-
    while(!q.empty())
    {
        // Take the front element out from the queue which will be our current element.
        int currRow = q.front().first; // As it is a pair the first will be current row.
        int currCol = q.front().second; // As it is a pair the second will be current col.
        q.pop(); // Pop the element out of the queue.

        // Now for this current row and col we have to traverse to all of it's 8 neighbours in the 8 directions which will be as follows:-
        // (row - 1, col), (row - 1, col + 1), (row, col + 1), (row + 1, col + 1) 
        // (row + 1, col), (row + 1, col - 1), (row, col - 1), (row - 1, col - 1)
        //                                 or
        // (-1, 0), (-1, 1), (0, 1), (1, 1)
        // (1, 0), (1, -1), (0, -1), (-1, -1)
        for(int newRow = -1; newRow <= 1; newRow++) // {-1, 0, 1}
        {
            for(int newCol = -1; newCol <= 1; newCol++) // {-1, 0, 1}
            {
                int neighbourRow = currRow + newRow; // Form the neighbour Row which will be currRow + newRow (e.g. currRow = 0, newRow = -1 => neighbourRow = -1)
                int neighbourCol = currCol + newCol; // Form the neighbour Col which will be currCol + newCol (e.g. currCol = 1, newCol = -1 => neighbourCol = 0)

                // Hence, the neighbouring element which we are going to traverse will be grid[-1][0] or (-1, 0) or (row - 1, col) which is top.
                // We will check before traversing the current element if it is out of bounds or if it is already not visited or if it is a land. Only if all the conditions are true we will be proceeding ahead with the traversal.
                if(neighbourRow >= 0 && neighbourRow < grid.size() && neighbourCol >= 0 && neighbourCol < grid[0].size() && visited[neighbourRow][neighbourCol] == false && grid[neighbourRow][neighbourCol] == 1)
                {
                    visited[neighbourRow][neighbourCol] = true; // Visit the current element.
                    q.push({neighbourRow, neighbourCol}); // Push the current element inside queue.
                }
            }
        }
    }
}

int countNumberOfIslands(vector<vector<int>>& grid)
{
    int row = grid.size(); // Number of rows in the grid.
    int col = grid[0].size(); // Number of columns in the grid.

    // Creating a 2D visited array.
    vector<vector<bool>> visited(row, vector<bool>(col, false)); // As discussed in the approach for the initial configuration visited array will be a 2D array as our input is also a 2D grid.

    int count = 0; // Counter for the counting number of islands.

    for(int i = 0; i < row; i++) // Iterate over each row of grid
    { 
        for(int j = 0; j < col; j++) // Iterate over each col of grid
        {
            if(visited[i][j] == false && grid[i][j] == 1) // If the current element grid[i][j] is not visited and if it is a land then:-
            {
                traverseBFS(i, j, grid, visited); // Traverse the land element and it's neighbouring land elements using BFS that will result in 1 island.
                count++; // After the traversal is done increase the count because one traversal will traverse a land and all it's neighbouring land which will form 1 big island.
            }
        }
    }
    return count; // Return the count.
}

int main()
{
    int row, col;
    cout << "Enter the number of rows and columns in the grid: " << endl;
    cin >> row >> col;

    cout << "Enter the elements of the grid: " << endl;
    vector<vector<int>> grid; // Input Grid is given in which we have to find the Number of Islands.
    for(int i = 0; i < row; i++)
    {
        vector<int> rows;
        for(int j = 0; j < col; j++)
        {
            int colValue;
            cin >> colValue;
            rows.push_back(colValue);
        }
        grid.push_back(rows);
    }

    int count = countNumberOfIslands(grid);
    cout << count << endl;
    return 0;
}