/******************************************************************************

Recursion - 32:- Josephus Problem / Find the Winner of the Circular Game

Time Complexity:- O(n^2); The loop will run from 1 to k for each killing.
Space Complexity:- O(n); n for auxiliary stack space.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void josephusProblemHelper(int index, int k, vector<int>& circle, int& out)
{
    int size = circle.size();
    if(size == 1)
    {
        out = circle[0];
        return;
    }
    
    index = (index + k) % size;
    circle.erase(circle.begin() + index);
    josephusProblemHelper(index, k, circle, out);
}

int josephusProblem(int n, int k) {
    int out = -1;
    vector<int> circle;
    for(int i = 1; i <= n; i++)
        circle.push_back(i);
        
    k = k - 1;
    josephusProblemHelper(0, k, circle, out);
    return out;
}


int main()
{
    int n, k;
    cin >> n >> k;
    int out = josephusProblem(n, k);
    cout << out << endl;
    return 0;
}