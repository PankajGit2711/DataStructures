/******************************************************************************

Recursion 6 - Reverse an Array (Two Pointer and Single Pointer)

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//Two Pointer
void reverseArrayTwoPointer(vector<int> &arr, int left, int right)
{
    if(left >= right)
        return; 
        
    swap(arr[left], arr[right]);
    reverseArrayTwoPointer(arr, left + 1, right - 1);
}

//Single Pointer
void reverseArraySinglePointer(vector<int> &arr, int size, int index)
{
    if(index >= size / 2)
        return;
        
    swap(arr[index], arr[size - index - 1]);
    reverseArraySinglePointer(arr, size, index + 1);
}

int main()
{
    vector<int> arr1{1,2,3,4,5};
    vector<int> arr2{1,2,3,4,5};
    
    reverseArrayTwoPointer(arr1, 0, 5 - 1);
    for(auto &it: arr1)
        cout << it << " ";
    cout << endl;
    
    reverseArraySinglePointer(arr2, 5, 0); 
    for(auto &it: arr2)
        cout << it << " ";
    cout << endl;
    return 0;
}