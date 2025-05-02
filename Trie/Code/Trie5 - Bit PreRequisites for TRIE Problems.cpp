#include <bits/stdc++.h> 

using namespace std;

// Formula:- num1 ^ num2
int XOR(int n, int m) 
{
    return n ^ m;
}

/* Formula:- (num >> i) & 1 == 0 then bit is not set
             (num >> i) & 1 != 0 then bit is set */
int checkIfBitIsSet(int a, int b) 
{
    return (b >> a - 1) & 1;
}

// Formula:- num | (1 << i)
int setBit(int c, int d) 
{
    return d | (1 << c);
}

int main()
{
    int n = 1, m = 2;
    int a = 3, b = 4;
    int c = 5, d = 6;
    
    cout << XOR(n, m) << endl;
    cout << checkIfBitIsSet(a, b) << endl;
    cout << setBit(c, d) << endl;
    
    return 0;
}