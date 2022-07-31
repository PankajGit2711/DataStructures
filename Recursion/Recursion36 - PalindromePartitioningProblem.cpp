/*********************************************************************************************

Recursion - 36:- Palindrome Partitioning Problem - Leetcode

Time Complexity:- O(2^n); For 2^n combinations of the string.
Space Complexity:- O(length * combinations)

*********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool isPartitionPalindrome(string str, int start, int end)
{
    while(start <= end)
    {
        if(str[start++] != str[end--])
            return false;
    }
    return true;
}

void palindromePartitioningHelper(int index, string str, vector<vector<string>>& out, vector<string>& temp)
{
    int size = str.size();
    if(index == size)
    {
        out.push_back(temp);
        return;
    }
    
    for(int i = index; i < size; i++)
    {
        if(isPartitionPalindrome(str, index, i))
        {
            temp.push_back(str.substr(index, i - index + 1));
            palindromePartitioningHelper(i + 1, str, out, temp);
            temp.pop_back();
        }
    }
}

vector<vector<string>> palindromePartitioning(string str) 
{
    vector<vector<string>> out;
    vector<string> temp;
    palindromePartitioningHelper(0, str, out, temp);
    return out;
}


int main()
{
    string str;
    cin >> str;
    
    vector<vector<string>> out = palindromePartitioning(str);
    
    for(auto &i: out)
    {
        for(auto &j: i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}