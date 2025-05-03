/*
GP6 - Number of Connected Components in a Graph

Time Complexity = O(V + E) where V is no. of nodes and E is no. of edges.
Space Complexity = O(2 * E) where E is no. of edges.

Tested with the following input gives following output
Input: Nodes = 10, Edges = 8, EdgesList = {[1, 2], [1, 3], [3, 4], [2, 4], [5, 6], [6, 7], [5, 7], [8, 9]}
Output: 4
*/ 

#include <bits/stdc++.h>

using namespace std;

void traverseGraph(int currentNode, vector<int> adjList[], vector<bool>& visited)
{
    // Method will contain current node which is being visited, adjList and visited array.

    visited[currentNode] = true; // Visit the current node and make it's entry true in visited array.
    for(auto &neighbour: adjList[currentNode]) // adjList[currentNode] will give the adjacent node or direct neighbour of the current node. 
    {
        if(visited[neighbour] == false)
            traverseGraph(neighbour, adjList, visited); // For all neighbour of the current node which are not visited, recursively call traverseGraph() method to visit them.
    }
}

int countNumberOfConnectedComponents(int nodes, int edges, vector<vector<int>>& edgesList)
{
    int count = 0;

    // Creating and filling adjacency list from given graph's edge list
    vector<int> adjList[nodes + 1];
    for(auto &edge: edgesList)
    {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Created an empty visited array initialized with all values as false;
    vector<bool> visited(nodes + 1, false);

    for(int i = 0; i < nodes; i++)
    {
        if(visited[i] == false)
        {
            traverseGraph(i, adjList, visited); // Only do the traversal if the node is not already visited.
            count++; // Once the traversal is done increase the count.
        }
    }
    return count;
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

    int count = countNumberOfConnectedComponents(nodes, edges, edgesList);

    cout << "Total Number of connected components inside the graph is: " << count << endl;
    return 0;
}

