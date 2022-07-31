/******************************************************************************

Recursion - 1:- Print Numbers from 1 to N

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void printNumbers(int n)
{
    if(n == 0)
        return;
    
    printNumbers(n - 1);
    cout << n << " ";
}

void printNumbers2(int i, int n)
{
    if(i > n)
        return;
        
    cout << i << " ";
    printNumbers2(i + 1, n);
}

int main()
{
    int n;
    cin >> n;
    printNumbers(n);
    cout << endl;
    printNumbers2(1, n);
    return 0;
}