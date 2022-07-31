/*************************************************************************************

Recursion - 16:- Sort an Stack Using Recursion (Recursive Insertion Sort)

Time Complexity:- O(n^2)     Space Complexity:- O(n)

**************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void insertElement(stack<int>& st, int temp)
{
    if(st.size() == 0 || st.top() <= temp)
    {
        st.push(temp);
        return;
    }  
    
    int value = st.top();
    st.pop();
    insertElement(st, temp);
    st.push(value);
}

void sortStack(stack<int>& st) 
{
    if(st.size() == 1)
        return;
    
    int temp = st.top();
    st.pop();
    sortStack(st);
    insertElement(st, temp);
}

int main()
{
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(5);

    sortStack(st);
    
    while(!st.empty())
    {
        int val = st.top();
        st.pop();
        cout << val << " ";
    }
    return 0;
}
