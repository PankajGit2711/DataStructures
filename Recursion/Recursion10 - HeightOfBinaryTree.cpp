/******************************************************************************

Recursion - 10:- Height of Binary Tree (Recursion on Trees)

Time Complexity = O(n)            Space Complexity:- O(n) 

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int heightOfTree(Node* root)
{
    if(root == NULL)
        return 0;
        
    int left = heightOfTree(root -> left);
    int right = heightOfTree(root -> right);
    
    return 1 + max(left, right);
}

int main()
{
    struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    
    cout << heightOfTree(root) << endl;
    return 0;
}