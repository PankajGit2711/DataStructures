/******************************************************************************

Recursion - 33:- N Queens Problem

Time Complexity:- O(n! * n); n! for trying out each combinations.
Space Complexity:- O(n); n for auxiliary stack space.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool isValidPosition(int i, int index, int n, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal)
{
    if(leftRow[i] == 0 && lowerDiagonal[i + index] == 0 && upperDiagonal[n - 1 + index - i] == 0)
        return true;
    return false;
}

void nQueenHelper(int col, int n, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, vector<string>& temp, vector<vector<string>>& out)
{
    if(col == n)
    {
        out.push_back(temp);
        return;
    }
    
    for(int row = 0; row < n; row++)
    {
        if(isValidPosition(row, col, n, leftRow, upperDiagonal, lowerDiagonal))
        {
            temp[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            nQueenHelper(col + 1, n, leftRow, upperDiagonal, lowerDiagonal, temp, out);
            temp[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}
vector<vector<string>> nQueen(int n) {
    vector<vector<string>> out;
    vector<string> temp(n);
    string s(n, '.');
    
    for(int i = 0; i < n; i++)
        temp[i] = s;
        
    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    nQueenHelper(0, n, leftRow, upperDiagonal, lowerDiagonal, temp, out);
    return out;
}


int main()
{
    int n;
    cin >> n;
    
    vector<vector<string>> out = nQueen(n);
    
    for(auto& i: out)
    {
        for(auto& j: i)
            cout << j << endl;
        cout << endl;
    }
    return 0;
}