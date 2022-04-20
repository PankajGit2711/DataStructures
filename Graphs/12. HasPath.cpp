// Time Complexity = O(N + E)
// Space Complexity = O(N + E) + O(N)

#include<bits/stdc++.h>
using namespace std;

bool hasPathHelper(vector<int> adjList[], vector<bool>& visited, int src, int dest)
{
    if(src == dest)
        return true;
        
    visited[src] = true;
    for(auto &neighbour: adjList[src])
    {
        if(visited[neighbour] == false)
        {
            bool hasPath = hasPathHelper(adjList, visited, neighbour, dest);
            if(hasPath == true)
                return true;
        }
    }
    return false;
}


int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    vector<int> adjList[nodes + 1];
    
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    int source, destination;
    cin >> source >> destination;
    
    vector<bool> visited(nodes + 1, false);
    
    bool out = hasPathHelper(adjList, visited, source, destination);

    cout << out << endl;
    
    return 0;
}