/******************************************************************************

Recursion - 29:- Letter Case Permutation of String - Leetcode

Time Complexity:- O(2^n); 2^n Permutation of string.
Space Complexity:- O(n); For Auxiliary stack space.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void letterCasePermutationHelper(string s, string temp, vector<string>& out)
{
    int size = s.size();
    if(size == 0)
    {
        out.push_back(temp);
        return;
    }
    
    if(isalpha(s[0]))
    {
        string output1 = temp;
        string output2 = temp;
        
        output1.push_back(tolower(s[0]));
        output2.push_back(toupper(s[0]));
        
        s.erase(s.begin() + 0);
        
        letterCasePermutationHelper(s, output1, out);
        letterCasePermutationHelper(s, output2, out);
    }
    
    else
    {
        string output1 = temp;
        output1.push_back(s[0]);
        s.erase(s.begin() + 0);
        letterCasePermutationHelper(s, output1, out);
    }
}

vector<string> letterCasePermutation(string s) 
{
    vector<string> out;
    string temp = "";
    letterCasePermutationHelper(s, temp, out);
    return out;
}


int main()
{
    string s = "a1B2";
    vector<string> out = letterCasePermutation(s);
    
    for(auto &it: out)
        cout << it << endl;
    return 0;
}