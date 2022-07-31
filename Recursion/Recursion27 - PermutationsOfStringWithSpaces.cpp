/***************************************************************************************

Recursion - 27:- Permutations of String with Spaces

Time Complexity:- O(n!); n! for all permutations.
Space Complexity:- O(n); and n for Auxiliary Space.

*****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void permutationsWithSpacesHelper(string s, string temp, vector<string>& out)
{
    int size = s.size();
    if(size == 0)
    {
        out.push_back(temp);
        return;
    }
    
    string temp1 = temp;
    string temp2 = temp;
    
    temp1.push_back(' ');
    temp1.push_back(s[0]);
    temp2.push_back(s[0]);
    
    s.erase(s.begin() + 0);
    permutationsWithSpacesHelper(s, temp1, out);
    permutationsWithSpacesHelper(s, temp2, out);
    return;
}

vector<string> permutationsWithSpaces(string& s) 
{
    vector<string> out;
    string temp = "";
    
    temp.push_back(s[0]);
    s.erase(s.begin() + 0);
    
    permutationsWithSpacesHelper(s, temp, out);
    return out;
}

int main()
{
    string s;
    cin >> s;
    
    vector<string> out = permutationsWithSpaces(s);
    
    for(auto &it: out)
        cout << it << endl;
    return 0;
}