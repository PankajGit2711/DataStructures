/*************************************************************************************

Recursion - 15:- Sort an Array Using Recursion (Recursive Insertion Sort)

Time Complexity:- O(n^2)     Space Complexity:- O(n)

**************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void insertElement(vector<int>& arr, int temp)
{
    if(arr.size() == 0 || arr[arr.size() - 1] <= temp)
    {
        arr.push_back(temp);
        return;
    }  
    
    int value = arr[arr.size() - 1];
    arr.pop_back();
    insertElement(arr, temp);
    arr.push_back(value);
}

void sortArray(vector<int>& arr) 
{
    if(arr.size() == 1)
        return;
    
    int temp = arr[arr.size() - 1];
    arr.pop_back();
    sortArray(arr);
    insertElement(arr, temp);
}

int main()
{
    vector<int> arr{5, 4, 3, 2, 1};
    sortArray(arr);
    
    for(auto &it: arr)
        cout << it << " ";
    cout << endl;
    return 0;
}
