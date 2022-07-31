/**************************************************************************************************************************

Recursion - 38:- Kth Permutation Sequence - Leetcode

Time Complexity:- O(n^2); As we are looking for n numbers and everytime we have to erase 1 number till we reach nth number.
Space Complexity:- O(n); Using vector to store numbers and recursion space.

***************************************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {
    int factorial = 1;
    string out = "";
    vector<int> numbers;
    k = k - 1;
    
    for(int i = 1; i < n; i++)
    {
        factorial = factorial * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    
    while(true)
    {
        out = out + to_string(numbers[k / factorial]);
        numbers.erase(numbers.begin() + k / factorial);
        
        if(numbers.size() == 0)
            break;
        
        k = k % factorial;
        factorial = factorial / numbers.size();
    }
    return out;
}


int main()
{
    int n, k;
    cin >> n >> k;
    
    string out = getPermutation(n, k);
    cout << out << endl;
    return 0;
}