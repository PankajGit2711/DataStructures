/******************************************************************************

Recursion - 2:- Print Name N Times

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void printName(int i, int n)
{
    if(i > n)
        return;
        
    cout << "Pankaj" << endl;
    printName(i + 1, n);
}

int main()
{
    int n;
    cin >> n;
    printName(1, n);
    return 0;
}