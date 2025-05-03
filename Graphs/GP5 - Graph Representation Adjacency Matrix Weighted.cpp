/*
GP5 - Weighted Graph Representation Via Adjacency List Undirected Graph

Space Complexity = O(n^2)
*/ 

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges in the graph: " << endl;
    cin >> nodes >> edges;

    // Creating adjacency matrix for weighted graph
    int adjMatrix[nodes + 1][edges + 1];

    cout << "Enter the individual nodes with the edge weight in between which you want to create an edge: " << endl;
    for(int i = 0; i < edges; i++)
    {
        int u, v, weights;
        cin >> u >> v >> weights;

        adjMatrix[u][v] = weights; // Instead of unit weights we are storing actual edge weights.
        adjMatrix[v][u] = weights; 
    }
    return 0;
}