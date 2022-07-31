/******************************************************************************

Recursion - 8:- Print Nth Fibonacci Number (Multiple Recursion Calls)

Time Complexity = O(2^n)            Space Complexity:- O(n) 

*******************************************************************************/
#include <iostream>
using namespace std;

int nthFibonacciNumber(int n)
{
    if(n <= 1)
        return n;
    
    int last = nthFibonacciNumber(n - 1);
    int secondLast = nthFibonacciNumber(n - 2);
    return last + secondLast;
}


int main()
{
    int n;
    cin >> n;
    cout<< nthFibonacciNumber(n) << endl;
    return 0;
}