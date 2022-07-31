/******************************************************************************

Recursion 5 - Factorial of N numbers (Parametrized and Functional Recursion)

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//Parametrized Method
void factorialOfNNumbersParmeterized(int i, int fact)
{
    if(i == 0)
    {
        cout << fact << endl;
        return;
    }
    factorialOfNNumbersParmeterized(i - 1, fact * i);
}

//Functional Method
int factorialOfNNumbersFunctional(int n)
{
    if(n == 1)
        return 1;
    return n * factorialOfNNumbersFunctional(n - 1);
}

int main()
{
    int n;
    cin >> n;
    factorialOfNNumbersParmeterized(n, 1);
    cout << factorialOfNNumbersFunctional(n) << endl;
    return 0;
}