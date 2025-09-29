/*
M1 - Broken Calculator

Details: There is a broken calculator that has the integer startValue on its display initially. In one operation, you can:

1. Multiply the number on display by 2, or 
2. Subtract 1 from the number on display.

Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.

Time Complexity = O(log(target)) // For reaching target to startValue, every time we either divide by 2 or subtract 1.
Space Complexity = O(1) // No additional space used.

Tested with the following input gives following output:
Input: 5, 8
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int BrokenCalculator(int startValue, int target)
{
    int operations = 0; // Initialize the operations counter

    // While the target is greater than the startValue
    while (target > startValue)
    {
        // If the target is even, divide it by 2
        if (target % 2 == 0)
            target /= 2;

        // If the target is odd, increment it by 1 to make it even
        else
            target += 1;

        operations++; // Increment the operations counter for each step
    }

    // Add the difference between startValue and target to the operations
    // This accounts for the remaining steps to reach the target
    operations += (startValue - target);
    return operations; // Return the total number of operations
}

int main()
{
    int startValue, target;

    cout << "Enter the start value and target: ";
    cin >> startValue >> target;

    int operations = BrokenCalculator(startValue, target);
    cout << "Minimum number of operations: " << operations << endl;
    return 0;
}