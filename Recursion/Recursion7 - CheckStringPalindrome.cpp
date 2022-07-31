/******************************************************************************

Recursion 7 - Check string is Palindrome (Two Pointer and Single Pointer)

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//Two Pointer
bool checkStringPalindromeTwoPointer(string &str, int left, int right)
{
    if(str[left] != str[right])
       return false; 
        
    checkStringPalindromeTwoPointer(str, left + 1, right - 1);
    return true;
}

//Single Pointer
bool checkStringPalindromeSinglePointer(string &str, int index, int size)
{
    if(str[index] != str[size - index - 1])
        return false;
    
    checkStringPalindromeSinglePointer(str, index + 1, size);
    return true;
}

int main()
{
    string str;
    cin >> str;
    int size = str.size();
    bool out1 = checkStringPalindromeTwoPointer(str, 0, size - 1);
    bool out2 = checkStringPalindromeSinglePointer(str, 0, size);
    
    if(out1)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;
        
    if(out2)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;
}