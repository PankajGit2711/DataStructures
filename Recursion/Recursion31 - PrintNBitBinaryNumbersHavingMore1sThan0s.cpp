/******************************************************************************

Recursion - 31:- Print N-bit binary numbers having more 1s than 0s

Time Complexity:- O(2^n); 2^n permutations of strings.
Space Complexity:- O(n); n for auxiliary stack space.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void NBitBinaryHelper(int N, int ones, int zeros, string temp, vector<string>& out)
{
    if(N == 0)
    {
        out.push_back(temp);
        return;
    }
    
    string output1 = temp;
    output1.push_back('1');
    NBitBinaryHelper(N - 1, ones + 1, zeros, output1, out);
    
    if(ones > zeros)
    {
        string output2 = temp;
        output2.push_back('0');
        NBitBinaryHelper(N - 1, ones, zeros + 1, output2, out);
    }
}

vector<string> NBitBinary(int N)
{
    vector<string> out;
    string temp = "";
    int ones = 0, zeros = 0;
    NBitBinaryHelper(N, ones, zeros, temp, out);
    return out;
}


int main()
{
    int n = 5;
    vector<string> out = NBitBinary(n);
    
    for(auto &it: out)
        cout << it << endl;
    return 0;
}