/*
GP3 - Graph Representation Via Adjacency List Directed Graph

Space Complexity = O(Edges) = O(E)
Because we will only have an edge from one node to another node.
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

        // Since it's a directed graph we will only have an edge from one node to another and not it's vice versa.
        adjList[u].push_back(v);
    }
    return 0;
}