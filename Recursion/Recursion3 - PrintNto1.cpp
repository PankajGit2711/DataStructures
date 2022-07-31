/******************************************************************************

Recursion - 3:- Print Numbers from N to 1

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void printNumbersBackwards(int n)
{
    if(n == 0)
        return;
    
    cout << n << " ";
    printNumbersBackwards(n - 1);
}

void printNumbersBackwards2(int i, int n)
{
    if(i < 1)
        return;
        
    cout << i << " ";
    printNumbersBackwards2(i - 1, n);
}

int main()
{
    int n;
    cin >> n;
    printNumbersBackwards(n);
    cout << endl;
    printNumbersBackwards2(n, n);
    return 0;
}