/******************************************************************************

Recursion - 30:- Generate Balanced Paranthesis - Leetcode

Time Complexity:- O(2^n); 2^n Permutation of string.
Space Complexity:- O(n); For Auxiliary stack space.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void generateParenthesisHelper(int open, int close, string temp, vector<string>& out)
{
    if(open == 0 && close == 0)
    {
        out.push_back(temp);
        return;
    }
    
    if(open != 0)
    {
        string output1 = temp;
        output1.push_back('(');
        generateParenthesisHelper(open - 1, close, output1, out);
    }
    
    if(close > open)
    {
        string output2 = temp;
        output2.push_back(')');
        generateParenthesisHelper(open, close - 1, output2, out);
    }
}
vector<string> generateParenthesis(int n) 
{
    vector<string> out;
    string temp = "";
    int open = n, close = n;
    generateParenthesisHelper(open, close, temp, out);
    return out;
}


int main()
{
    int n = 3;
    vector<string> out = generateParenthesis(n);
    
    for(auto &it: out)
        cout << it << endl;
    return 0;
}