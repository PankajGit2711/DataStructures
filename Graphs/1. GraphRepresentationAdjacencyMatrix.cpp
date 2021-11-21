#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    int adj[nodes+1][nodes+1];
    
    for(int i = 0; i < edges; i++)
    {
        int u, v; // u and v represents node 1 and node 2 which are connected by an edge.
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}
