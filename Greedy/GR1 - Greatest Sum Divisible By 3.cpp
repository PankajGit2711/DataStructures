/*
GR1 - Greatest Sum Divisible By 3

Details: Given an array of integers, find the maximum possible sum of elements
that is divisible by 3. You may remove the minimum necessary elements to make
the remaining sum divisible by 3.

Approach:
1. Calculate the total sum of the array.
2. Track the smallest numbers with remainders 1 and 2 when divided by 3.
3. Adjust the total sum by removing the smallest necessary elements to make it divisible by 3.

Time Complexity: O(n) // Single pass to compute the sum and track the smallest remainders.
Space Complexity: O(1) // Constant extra space.

Example:
Input: [3, 6, 5, 1, 8]
Output: 18
Explanation: The sum of all elements is 23. Removing 5 gives a sum of 18, which is divisible by 3.
*/

#include <bits/stdc++.h>

using namespace std;

int maxSumDivThree(vector<int>& nums) 
{
    int smallestOne = INT_MAX, smallestTwo = INT_MAX; // Variables to track the smallest numbers with remainders 1 and 2
    int totalSum = 0; // Total sum of all elements in the array

    // Iterate through the array to calculate the total sum and track the smallest remainders
    for(int i = 0; i < nums.size(); i++)
    {
        totalSum += nums[i]; // Add the current number to the total sum
        if(nums[i] % 3 == 1) // Check if the current number leaves a remainder of 1 when divided by 3
        {
            if(smallestOne != INT_MAX)
                smallestTwo = min(smallestTwo, nums[i] + smallestOne); // Update the second smallest number with remainder 1
            
            smallestOne = min(smallestOne, nums[i]); // Update the smallest number with remainder 1
        }

        if(nums[i] % 3 == 2) // Check if the current number leaves a remainder of 2 when divided by 3
        {
            if(smallestTwo != INT_MAX)
                smallestOne = min(smallestOne, nums[i] + smallestTwo); // Update the smallest number with remainder 1
            
            smallestTwo = min(smallestTwo, nums[i]); // Update the smallest number with remainder 2
        }
    }

    if(totalSum % 3 == 0)
        return totalSum; // If the total sum is already divisible by 3, return it

    if(totalSum % 3 == 1)
        return totalSum - smallestOne; // If the total sum leaves a remainder of 1, subtract the smallest number with remainder 1

    if(totalSum % 3 == 2)
        return totalSum - smallestTwo; // If the total sum leaves a remainder of 2, subtract the smallest number with remainder 2

    return 0; // Default return (should not reach here)
}

int main()
{
    cout << "Enter the number of elements followed by the elements themselves: ";
    int n; 
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int result = maxSumDivThree(nums);
    cout << "Maximum sum divisible by 3: " << result << endl;
    return 0;
}