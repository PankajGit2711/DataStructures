#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    vector<int> adj[nodes+1];
    
    for(int i = 0; i < edges; i++)
    {
        int u, v; // u and v represents node 1 and node 2 which are connected by an edge.
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
