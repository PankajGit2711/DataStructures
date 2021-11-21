#include<bits/stdc++.h>
using namespace std;

void connectedComponentDFS(int child, vector<int> adjList[], vector<int> &visited)
{
    visited[child] = 1;
    for(auto it: adjList[child])
    {
        if(visited[it] == 0)
            connectedComponentDFS(it, adjList, visited);
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adjList[nodes+1];
    
    for(int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int count = 0;
    vector<int> visited(nodes+1, 0);

    for(int i = 1; i <= nodes; i++)
    {
        if(visited[i] == 0){
            connectedComponentDFS(i, adjList, visited);
            count++;
        }
    }
    cout << count << endl;
}
