/*
GP4 - Weighted Graph Representation Via Adjacency List Undirected Graph

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

    // Creating adjacency list for weighted graph
    vector<pair<int, int>> adjList[nodes + 1]; // Nodes + 1 indexes having an empty vector of pair<int, int> where first is adjacent node and second is weight.

    cout << "Enter the individual nodes with the edge weight in between which you want to create an edge: " << endl;
    for(int i = 0; i < edges; i++)
    {
        int u, v, weights;
        cin >> u >> v >> weights;

        adjList[u].push_back({v, weights}); // Weights are also added in the graph with the adjacent nodes.
        adjList[v].push_back({u, weights});
    }
    return 0;
}