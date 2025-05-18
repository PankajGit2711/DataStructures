/*
GP8 - Depth First Search Traversal in a Graph

Time Complexity = O(V) + O(2 * Edges) = O(V + 2E) = O(V + E) // Runs for all nodes and for each node it will run for all of it's degrees which is 2 * Edges for a node.
Space Complexity = O(N) + O(N) = O(2N) = O(N) // Visited Array + Adjacency List

Tested with the following input gives following output
Input: Nodes = 8, Edges = 8, EdgesList = {[1, 2], [1, 3], [2, 5], [2, 6], [3, 4], [3, 7], [7, 8], [4, 8]}
Output: 1 -> 2 -> 5 -> 6 -> 3 -> 4 -> 8 -> 7  
*/ 

#include<bits/stdc++.h>
using namespace std;

void depthFirstSearch(int currentNode, vector<int> adjList[], vector<int>& out, vector<bool>& visited)
{
    visited[currentNode] = true; // As soon as we come into this function mark the current node as visited.
    out.push_back(currentNode); // Add that node in the output.

    // For each neighbour of the current node do the following.
    for(auto& neighbour: adjList[currentNode])
    {
        // Check if it is visited or not, if visited ignore it.
        if(visited[neighbour] == false)
            depthFirstSearch(neighbour, adjList, out, visited); // If not visited call the same function recursively for that neighbour node and visit it. 
    }
}

vector<int> traverseDFS(int nodes, vector<int> adjList[])
{
    vector<int> out;
    vector<bool> visited(nodes + 1, false); // Initialised the visited array with all nodes value as false

    depthFirstSearch(1, adjList, out, visited); // Called the depthFirstSearch() with the starting node as 1.

    return out; // Returned the output
}

vector<int> printDFSTraversal(int nodes, int edges, vector<vector<int>>& edgesList)
{
    // Creating the adjacency list from the given graph's edgesList
    vector<int> adjList[nodes + 1];
    
    for(auto& edge: edgesList)
    {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> out = traverseDFS(nodes, adjList);
    return out;
}


int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges in the graph: " << endl;
    cin >> nodes >> edges;

    vector<vector<int>> edgesList;
    cout << "Enter the individual nodes in between which you want to create an edge: " << endl;
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        edgesList.push_back({u, v});   
    }

    vector<int> out = printDFSTraversal(nodes, edges, edgesList);

    for(auto& node: out)
        cout << node << " -> "; 

    return 0;
}