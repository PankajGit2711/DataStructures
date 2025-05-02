#include <bits/stdc++.h> 

using namespace std;

struct TrieNode
{
    TrieNode* links[26];
    bool flag;

    TrieNode* getInsideNode(char ch)
    {
        return links[ch - 'a'];
    }

    void putInsideNode(TrieNode* node, char ch)
    {
        links[ch - 'a'] = node;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    bool isEnd()
    {
        return flag;
    }

    void setEnd()
    {
        flag = true;
    }
};

class Trie
{
private:
    TrieNode* root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i]))
                node->putInsideNode(new TrieNode(), word[i]);

            node = node->getInsideNode(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i]))
                return false;

            node = node->getInsideNode(word[i]);

            if(node->isEnd() == false)
                return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie trie;
    string out = "";

    for(int i = 0; i < n; i++)
        trie.insert(a[i]);

    for(int i = 0; i < n; i++)
    {
        string curr = a[i];
        if(trie.search(curr))
        {
            if(curr.size() > out.size())
                out = curr;

            if(curr.size() == out.size() && curr < out)
                out = curr;
        }
    }
    return out == "" ? "None" : out;
}

int main()
{
    vector<string> arr1 {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    cout << completeString(arr1.size(), arr1) << endl;
    
    vector<string> arr2 {"ab" "bc"};
    cout << completeString(arr2.size(), arr2) << endl;
    
    return 0;
}