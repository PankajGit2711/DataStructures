/*************************************************************************************

Recursion - 20:- Delete Middle Element of Stack

Time Complexity:- O(k); where k = Middle Element
Space Complexity:- O(n); Auxiliary Recursive Stack Space

**************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void deleteMiddleElementStackHelper(stack<int>& st, int middle)
{
    if(middle == 1)
    {
        st.pop();
        return;
    }
    
    int val = st.top();
    st.pop();
    deleteMiddleElementStackHelper(st, middle - 1);
    st.push(val);
}

stack<int> deleteMiddleElementStack(stack<int>& st) 
{
    int size = st.size();
    
    if(size == 0)
        return st;
        
    int middle = floor(size / 2) + 1; 
    
    deleteMiddleElementStackHelper(st, middle);
    return st;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    stack<int> out = deleteMiddleElementStack(st);

    while(!out.empty())
    {
        int val = out.top();
        out.pop();
        cout << val << " ";
    }
    return 0;
}
