#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    vector<pair<int, int>> adj[nodes+1];
    
    for(int i = 0; i < edges; i++)
    {
        int u, v, wt; // u and v represents node 1 and node 2 which are connected by an edge.
        cin >> u >> v >> wt;
        
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    return 0;
}
