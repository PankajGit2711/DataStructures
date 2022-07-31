/******************************************************************************

Recursion 4 - Sum first N numbers (Parametrized and Functional Recursion)

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//Parametrized Method
void sumfirstNNumbersParmeterized(int i, int sum)
{
    if(i < 0)
    {
        cout << sum << endl;
        return;
    }
    sumfirstNNumbersParmeterized(i - 1, sum + i);
}

//Functional Method
int sumfirstNNumbersFunctional(int n)
{
    if(n == 0)
        return 0;
    return n + sumfirstNNumbersFunctional(n - 1);
}

int main()
{
    int n;
    cin >> n;
    sumfirstNNumbersParmeterized(n, 0);
    cout << sumfirstNNumbersFunctional(n) << endl;
    return 0;
}