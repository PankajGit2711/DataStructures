#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

struct TrieNode
{
    TrieNode* links[26];
    int endsWith = 0, countPrefix = 0;

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

    void incrementEndsWith()
    {
        endsWith++;
    }

    void decrementEndsWith()
    {
        endsWith--;
    }

    int getEndsWith()
    {
        return endsWith;
    }

    void incrementCountPrefix()
    {
        countPrefix++;
    }

    void decrementCountPrefix()
    {
        countPrefix--;
    }

    int getCountPrefix()
    {
        return countPrefix;
    }
};


class Trie{

private:
    TrieNode* root;

public:

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode* node = root;

        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i]))
                node->putInsideNode(new TrieNode(), word[i]);

            node = node->getInsideNode(word[i]);
            node->incrementCountPrefix();
        }
        node->incrementEndsWith();
    }

    int countWordsEqualTo(string word){
        TrieNode* node = root;

        for(int i = 0; i < word.size(); i++)
        {
            if(node->containsKey(word[i]))
                node = node->getInsideNode(word[i]);
            else
                return 0;
        }
        return node->getEndsWith();
    }

    int countWordsStartingWith(string word){
        TrieNode* node = root;

        for(int i = 0; i < word.size(); i++)
        {
            if(node->containsKey(word[i]))
                node = node->getInsideNode(word[i]);
            else
                return 0;
        }
        return node->getCountPrefix();
    }

    void erase(string word){
        TrieNode* node = root;

        for(int i = 0; i < word.size(); i++)
        {
            if(node->containsKey(word[i]))
                node = node->getInsideNode(word[i]);
            
            node->decrementCountPrefix();
        }
        node->decrementEndsWith();
    }
};


int main()
{
    vector<string> words {"an", "apple", "a", "ayaan", "ayaan", "axe", "bcd"};
    
    Trie trie;
    
    for(int i = 0; i < words.size(); i++)
    {
        trie.insert(words[i]);
    }
    
    cout << trie.countWordsEqualTo("ayaan") << endl;
    cout << trie.countWordsStartingWith("a") << endl;
    
    trie.erase("bcd");
    
    cout << trie.countWordsEqualTo("bcd") << endl;
    cout << trie.countWordsStartingWith("b") << endl;
    
    return 0;
}