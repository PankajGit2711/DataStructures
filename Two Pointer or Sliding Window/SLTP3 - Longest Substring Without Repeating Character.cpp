/*
SLTP - Longest Substring Without Repeating Characters

Time Complexity = O(n) // Array is traversed only one time completely
Space Complexity = O(1) // No additional space used.

Tested with the following input gives following output
Input: "abcabcbb"
Output: 3
*/ 

#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstringWithoutRepeatingCharacters(string s)
{
    int size = s.size();
    int left = 0, right = 0; // Take i = left, j = right two pointers to maintain the variable size sliding window.
    int maxLength = 0; // Also maintain a maxLength variable as well to keep track of the maximum length of substring without repeating characters which is also our output.
    map<int, int> wordMap; // Also create a map{character -> character index} which will tell us the if the character already exists and if exists what was the last index it appeared on.

    /*
    1. Here the approach is right pointer will move and left will stay at start.
    2. While traversing the string we keep on adding each character => s[right] inside the map along with it's index => right
    3. As soon as we encounter a character that has appeared before (through the map), only then will we update the left pointer index to max(left, right + 1).
    4. At every iteration we will also check if our current length is maximum then the previously computed max length.
    */

    while(right < size) // Traverse the string through right pointer
    {
        if(wordMap.count(s[right]) > 0) // Check if it is already existing in the map meaning it has appeared before in the string.
            left = max(left, wordMap[s[right]] + 1); // If the above condition is true update the left pointer.

        wordMap[s[right]] = right; // Otherwise only add the character in the map along with it's current index.
        maxLength = max(maxLength, right - left + 1); // Keep on checking and updating the maxLength at each iteration.
        right++; // Increment right pointer to keep the traversal running.
    }
    return maxLength; // Return maxLength at the end as an output.
}

int main()
{
    string s;
    cout << "Enter the string: " << endl;
    cin >> s;

    int out = lengthOfLongestSubstringWithoutRepeatingCharacters(s);
    cout << "Length of Longest Substring Without Repeating Characters is: " << out << endl;
    return 0;
}