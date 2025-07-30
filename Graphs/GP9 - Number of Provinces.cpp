/*
GP9 - Number of Provinces in a Graph with Graph as Adjacency Matrix

Time Complexity = O(N) + O(V + E) // Runs for all nodes and for each node it will run for all of it's degrees which is 2 * Edges for a node.
Space Complexity = O(N) + O(N) = O(2N) // Visited Array + Recursion Stack Space.

Tested with the following input gives following output
Input: Nodes = 3, Edges List (Given as Adjacency Matrix) = {[1, 1, 0], [1, 1, 0], [0, 0, 1]}
Output: 2 
*/ 

#include <bits/stdc++.h>

using namespace std;

void traverseDFS(int currentNode, vector<int> adjList[], vector<bool>& visited)
{
    visited[currentNode] = true; // As soon as we come into this function mark the current node as visited.

    // For each neighbour of the current node do the following.
    for(auto& neighbour: adjList[currentNode])
    {
        // Check if it is visited or not, if visited ignore it.
        if(visited[neighbour] == false)
            traverseDFS(neighbour, adjList, visited); // If not visited call the same function recursively for that neighbour node and visit it. 
    }
}

int countNumberOfProvinces(vector<vector<int>>& edgesList)
{
    // As the input edges list is given in the form of a Adjacency matrix we will first convert this adjacency matrix to adjacency list.
    // The code for that is as follows:-
    int size = edgesList.size();

    vector<int> adjList[size + 1]; // Created the adjacency list of nodes + 1 size.
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            // Nodes will be connected in the adjacency matrix if matrix[i][j] == 1. Here we are checking that only.
            if(edgesList[i][j] == 1 && i != j) // Also we are checking i != j for making sure that we are not taking self connections inside the adjacency list. 
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    int count = 0; // This will keep the count of provinces / connected components.
    vector<bool> visited(size + 1, false); // Created visited array with all nodes indexes as false.

    for(int i = 0; i < size; i++) // Run a loop over all the nodes in the array and do the following.
    {
        if(visited[i] == false) // If the node is already visited ignore it. If not then do the following.
        {
            count++; // Increase the count of provinces.
            traverseDFS(i, adjList, visited); // Visit the node and it's adjacent nodes.
        }
    }
    return count; // Return the count at the end.
}

int main()
{
    int nodes, edge;
    cin >> nodes;

    vector<vector<int>> edgesList; // Input Edges List is given in the form of a Adjacency Matrix.
    for(int i = 0; i < nodes; i++)
    {
        vector<int> edges;
        for(int j = 0; j < nodes; j++)
        {
            cin >> edge;
            edges.push_back(edge);
        }
        edgesList.push_back(edges);
    }

    int count = countNumberOfProvinces(edgesList);
    cout << count << endl;
    return 0;
}