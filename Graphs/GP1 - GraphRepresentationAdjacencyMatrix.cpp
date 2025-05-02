// Space Complexity - O(n^2)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    // Declare the adjacency matrix with length one more than no. of nodes and edges.
    int adj[nodes+1][nodes+1];
    
    // Take edges as input
    for(int i = 0; i < edges; i++)
    {
        int u, v; // u and v represents node 1 and node 2 which are connected by an edge.
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}
