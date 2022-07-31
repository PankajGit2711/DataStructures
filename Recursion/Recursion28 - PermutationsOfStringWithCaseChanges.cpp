/***************************************************************************************

Recursion - 28:- Permutations of String with Case Changes

Time Complexity:- O(n!); n! for all permutations.
Space Complexity:- O(n); n for Auxiliary Space.

*****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void permutationsWithCaseChangeHelper(string s, string temp, vector<string>& out)
{
    int size = s.size();
    if(size == 0)
    {
        out.push_back(temp);
        return;
    }
    
    string temp1 = temp;
    string temp2 = temp;
    
    temp1.push_back(s[0]);
    temp2.push_back(toupper(s[0]));
    
    s.erase(s.begin() + 0);
    permutationsWithCaseChangeHelper(s, temp1, out);
    permutationsWithCaseChangeHelper(s, temp2, out);
}

vector<string> permutationsWithCaseChange(string& s) 
{
    vector<string> out;
    string temp = "";
    permutationsWithCaseChangeHelper(s, temp, out);
    return out;
}

int main()
{
    string s;
    cin >> s;
    
    vector<string> out = permutationsWithCaseChange(s);
    
    for(auto &it: out)
        cout << it << endl;
    return 0;
}