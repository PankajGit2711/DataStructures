#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Trie
{
    Trie* links[26];
    bool flag = false;
    
    Trie* getInsideNode(char ch)
    {
        return links[ch - 'a'];
    }
    
    void putInsideNode(char ch, Trie* node)
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


class TrieClass
{
private:
    Trie* root;

public:   
    TrieClass()
    {
        root = new Trie();
    }
    
    void insert(string word) 
    {
        Trie* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i]))
                node->putInsideNode(word[i], new Trie());
                    
            node = node->getInsideNode(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) 
    {
        Trie* node = root;
        
        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containsKey(word[i]))
                return false;
                
            node = node->getInsideNode(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) 
    {
        Trie* node = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            if(!node->containsKey(prefix[i]))
                return false;
                
            node = node->getInsideNode(prefix[i]);
        }
        return true;
    }

};


int main()
{
    vector<string> words {"an", "apple", "a", "ayaan", "axe", "bcd"};
    
    TrieClass trie;
    
    for(int i = 0; i < words.size(); i++)
    {
        trie.insert(words[i]);
    }
    
    cout << trie.search("ayan") << endl;
    cout << trie.startsWith("app") << endl;
    return 0;
}