/******************************************************************************

Recursion - 21:- Reverse a Stack using Recursion

Time Complexity:- O(n)
Space Complexity:- O(2n); where n is Auxiliary stack space

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

void insertElement(stack<int>& st, int element)
{
    if(st.size() == 0)
    {
        st.push(element);
        return;
    }   
    int val = st.top();
    st.pop();
    insertElement(st, element);
    st.push(val);
}

void reverseStack(stack<int>& st)
{
    if(st.size() == 1)
        return;
        
    int val = st.top();
    st.pop();
    reverseStack(st);
    insertElement(st, val);
}


int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    reverseStack(st);
    
    while(!st.empty())
    {
        int val = st.top();
        st.pop();
        cout << val << " ";
    }
    return 0;
}