/*
GP2 - Graph Representation Via Adjacency List Undirected Graph

Space Complexity = O(2 * Edges) = O(2E)
Because the graph is undirected we can go from one node to another node and we can do it's vice versa as well so it's similar to having 2 edges between nodes.
*/ 

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges in the graph: " << endl;
    cin >> nodes >> edges;

    // Creating the adjacency list
    vector<int> adjList[nodes + 1]; // Nodes + 1 indexes having an empty vector of integers.

    cout << "Enter the individual nodes in between which you want to create an edge: " << endl;
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        // Here instead of storing edge weights to denote a connection we will just stores the nodes adjacent to a particular node.
        adjList[u].push_back(v); // In this case v is adjacent to u
        adjList[v].push_back(u); // In this case u is adjacent to v
    }
    return 0;
}