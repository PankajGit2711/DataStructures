#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
    TrieNode* links[26];

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
};

class Trie
{
private:
    TrieNode* root;

public:
    int length = 0;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string& word)
    {
        for(int i = 0; i < word.size(); i++)
        {
            TrieNode* node = root;
            for(int j = i; j < word.size(); j++)
            {
                if(!node->containsKey(word[j]))
                {
                    node->putInsideNode(new TrieNode(), word[j]);
                    length++;
                }
                node = node->getInsideNode(word[j]);
            }
        }
    }
};


int countDistinctSubstrings(string &s)
{
    Trie trie;

    trie.insert(s);

    return trie.length + 1;
}

int main()
{
    string s = "sds";
    cout << countDistinctSubstrings(s) << endl;
    return 0;
}