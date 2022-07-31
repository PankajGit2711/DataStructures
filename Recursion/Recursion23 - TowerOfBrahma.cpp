/******************************************************************************

Recursion - 23:- Tower of Brahma / Tower of Hanoi

Time Complexity:- O(2^n)
Space Complexity:- O(n); where n is Auxiliary stack space

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void towerOfBrahma(int n, int from, int to, int aux, int& count) 
{
    count++;
    if(n == 1)
    {
        cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        return;
    }
    
    towerOfBrahma(n - 1, from, aux, to, count);
    cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
    towerOfBrahma(n - 1, aux, to, from, count);
}

int main()
{
    int n, count = 0;
    cin >> n;
    towerOfBrahma(n, 1, 3, 2, count);
    cout << count << endl;
    return 0;
}