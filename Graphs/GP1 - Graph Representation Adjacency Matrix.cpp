/*
GP1 - Graph Representation Via Adjacency Matrix

Space Complexity = O(n^2)
*/ 

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges in the graph: " << endl;
    cin >> nodes >> edges;

    // Creating the adjacency matrix
    int adjMatrix[nodes + 1][edges + 1]; // As Graph has one based indexing so we are taking nodes + 1 and edges + 1

    cout << "Enter the individual nodes in between which you want to create an edge: " << endl;
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1; // Edge weight not given we will consider unit weight i.e. 1
        adjMatrix[v][u] = 1; // For undirected graph we have to create edges bidirectionally (u -> v, v -> u) by default.
    }
    return 0;
}