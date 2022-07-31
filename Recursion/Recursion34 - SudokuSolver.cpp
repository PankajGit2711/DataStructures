/*********************************************************************************************

Recursion - 34:- Sudoku Solver - Leetcode

Time Complexity:- O(9^(n ^ 2)); For each cell in the n^2 board, we have 9 possible numbers.
Space Complexity:- O(n); For Auxiliary Stack Space.

*********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool isValidNumber(char num, int row, int col, char grid[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        if(grid[row][i] == num)
            return false;
        if(grid[i][col] == num)
            return false;
        if(grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return false;
    }
    return true;
}

bool solveSudokuHelper(char grid[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(grid[i][j] == '.')
            {
                for(char num = '1'; num <= '9'; num++)
                {
                    if(isValidNumber(num, i, j, grid))
                    {
                        grid[i][j] = num;
                        
                        if(solveSudokuHelper(grid) == true)
                            return true;
                        
                        grid[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool SolveSudoku(char grid[9][9])  
{ 
    return solveSudokuHelper(grid);
}


int main()
{
    char grid[9][9] = {{'9', '5', '7', '.', '1', '3', '.', '8', '4'},
                       {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
                       {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
                       {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
                       {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
                       {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
                       {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
                       {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
                       {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};
                       
    SolveSudoku(grid);
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    return 0;
}