// Time Complexity = O(N + E)
// Space Complexity = O(N + E) + O(N) + O(N)

#include<bits/stdc++.h>
using namespace std;

void dfsGraph(int node, vector<bool>& visited, vector<int> adj[], vector<int>& out)
{
    out.push_back(node);
    visited[node] = true;
    for(auto &neighbour: adj[node])
    {
        if(visited[neighbour] == false)
            dfsGraph(neighbour, visited, adj, out);
    }
}


int main()
{
    int V, E;
    cin >> V >> E;
    
    vector<int> adj[V+1];
    
    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> out;
    vector<bool> visited(V + 1, false);
    
    for(int i = 1; i <= V; i++)
    {
        if(visited[i] == false)
            dfsGraph(i, visited, adj, out);
    }
    
    for (auto &it: out) {
        cout << it << ' ';
    }
    cout << endl;
    
    return 0;
}